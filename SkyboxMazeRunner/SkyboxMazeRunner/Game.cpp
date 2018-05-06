//
// Game.cpp
//

#include "pch.h"
#include "Game.h"
#include "Wall.h"
#include "EndPoint.h"

extern void ExitGame();

using namespace DirectX;
using namespace DirectX::SimpleMath;

using Microsoft::WRL::ComPtr;

XMGLOBALCONST XMVECTORF32 DeepDarkGray = { { { 0.150000000f, 0.150000000f, 0.150000000f, 1.000000000f } } };
static const float ROTATION_GAIN = 0.004f;
static const float MOVEMENT_GAIN = 0.07f;

Game::Game() :
	m_window(nullptr),
	m_outputWidth(800),
	m_outputHeight(600),
	m_featureLevel(D3D_FEATURE_LEVEL_9_1)
{
}

void Game::Initialize(HWND window, int width, int height)
{
    m_window = window;
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

	m_CollidableEntities.reserve(256);
	m_Maze.NewMaze(11);
	Vector3 mazeStart = m_Maze.getStartPosition();
	m_StartPosition = Vector3(mazeStart.x * (200 * 0.06f), 2.0f, mazeStart.z *(200 * 0.06f));

    CreateDevice();

    CreateResources();
    
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    
	m_keyboard = std::make_unique<DirectX::Keyboard>();
	m_mouse = std::make_unique<DirectX::Mouse>();
	m_mouse->SetWindow(window);
	m_GamePad = std::make_unique<DirectX::GamePad>();
}

void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}

void Game::Update(DX::StepTimer const& timer)
{
	float elapsedTime = float(timer.GetElapsedSeconds());

	float time = float(timer.GetTotalSeconds());
	auto kb = m_keyboard->GetState();	
	auto mouse = m_mouse->GetState();
	auto gamepad = m_GamePad->GetState(PLAYER_ONE);

	// Game Inputs (for non-game mechanic controls)
	if (kb.Escape || gamepad.buttons.back)
	{
		PostQuitMessage(0);
	}
	
	if (kb.Z || gamepad.buttons.rightStick)
	{
		mCollisionsEnabled = !mCollisionsEnabled;
	}

	if (m_GameEnd && kb.E || gamepad.buttons.a)
	{
		//restart the game
		ResetGame();
	}


	if (!m_GameEnd)
	{
		if (mouse.positionMode == Mouse::MODE_RELATIVE)
		{
			m_Camera->Update(mouse, kb, gamepad);
		}

		m_mouse->SetMode(Mouse::MODE_RELATIVE);

		//only check if collisions are enabled
		if (mCollisionsEnabled)
		{
			ProcessCollisions();
		}
		else
		{
			m_Camera->Move();
		}

		m_Floor->Update(time);
		for (Entity*& ntt : m_CollidableEntities)
		{
			ntt->Update(time);
		}
	}
    elapsedTime;
}

void Game::ProcessCollisions()
{
	m_Collision = false;
	Vector3 nttPos;
	int nttIndex = 0;


	Vector3 previewMove = m_Camera->getPreviewMove();
	CollisionSphere cameraCollider = m_Camera->getCollisionSphere();

	for (size_t i = 0; i < m_CollidableEntities.size(); ++i)
	{
		BoundingBox aabb = m_CollidableEntities[i]->GetAABB();
		if (aabb.Intersects(cameraCollider.sphere))
		{
			nttPos = aabb.Center;
			nttIndex = i;
			m_Collision = true;
			goto continueProcessing;
		}
		
	}
	
	continueProcessing:

	if (!m_Collision)
	{
		m_Camera->Move();
	}
	else
	{
		switch (m_CollidableEntities[nttIndex]->GetTag())
		{
			case Entity::EntityTag::Wall:
				m_Camera->handleCollision(nttPos);
				break;

			case Entity::EntityTag::End:
				m_GameEnd = true;
				break;

		}
	}
}


// Draws the scene.
void Game::Render()
{
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    Clear();

	m_Floor->Render(m_d3dContext.Get(), *m_states, m_Camera->getView(), m_Camera->getProj());
	for (Entity*& ntt : m_CollidableEntities)
	{
		ntt->Render(m_d3dContext.Get(), *m_states, m_Camera->getView(), m_Camera->getProj());
	}

	m_SpriteBatch->Begin();
	if (m_GameEnd)
	{
		const wchar_t* text;
		
		if (!m_GamePad->GetState(PLAYER_ONE).IsConnected())
		{
			text = L"MAZE COMPLETE\n\nPress E to star again or ESC to exit";
		}
		else
		{
			text = L"MAZE COMPLETE\n\nPress A to star again or BACK to exit";
		}

		Vector2 origin = m_Font->MeasureString(text) / 2.0f;
		m_Font->DrawString(m_SpriteBatch.get(), text, m_FontPos, Colors::Snow, 0.0f, origin);
	}

	if (m_Collision && !m_GameEnd)
	{
		const wchar_t* text = L"Collision!";
		Vector2 origin = m_Font->MeasureString(text) / 2.0f;
		m_Font->DrawString(m_SpriteBatch.get(), text, m_FontPos, Colors::Snow, 0.0f, origin);
	}

	m_SpriteBatch->End();

    Present();
}

void Game::Clear()
{
    m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), DeepDarkGray);
    m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

    m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(m_outputWidth), static_cast<float>(m_outputHeight));
    m_d3dContext->RSSetViewports(1, &viewport);
}

void Game::Present()
{
    HRESULT hr = m_swapChain->Present(1, 0);

    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    {
        OnDeviceLost();
    }
    else
    {
        DX::ThrowIfFailed(hr);
    }
}

void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    CreateResources();
}

void Game::GetDefaultSize(int& width, int& height) const
{
    width = 1280;
    height = 720;
}

void Game::CreateDevice()
{
    UINT creationFlags = 0;

#ifdef _DEBUG
    creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    static const D3D_FEATURE_LEVEL featureLevels [] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
        D3D_FEATURE_LEVEL_9_3,
        D3D_FEATURE_LEVEL_9_2,
        D3D_FEATURE_LEVEL_9_1,
    };

   
    ComPtr<ID3D11Device> device;
    ComPtr<ID3D11DeviceContext> context;
    DX::ThrowIfFailed(D3D11CreateDevice(
        nullptr,                           
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        creationFlags,
        featureLevels,
        _countof(featureLevels),
        D3D11_SDK_VERSION,
        device.ReleaseAndGetAddressOf(),   
        &m_featureLevel,                    
        context.ReleaseAndGetAddressOf()    
        ));

#ifndef NDEBUG
    ComPtr<ID3D11Debug> d3dDebug;
    if (SUCCEEDED(device.As(&d3dDebug)))
    {
        ComPtr<ID3D11InfoQueue> d3dInfoQueue;
        if (SUCCEEDED(d3dDebug.As(&d3dInfoQueue)))
        {
#ifdef _DEBUG
            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
#endif
            D3D11_MESSAGE_ID hide [] =
            {
                D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS,
            };
            D3D11_INFO_QUEUE_FILTER filter = {};
            filter.DenyList.NumIDs = _countof(hide);
            filter.DenyList.pIDList = hide;
            d3dInfoQueue->AddStorageFilterEntries(&filter);
        }
    }
#endif

    DX::ThrowIfFailed(device.As(&m_d3dDevice));
    DX::ThrowIfFailed(context.As(&m_d3dContext));

	m_Font = std::make_unique<SpriteFont>(m_d3dDevice.Get(), L"myfile.spritefont");
	m_SpriteBatch = std::make_unique<SpriteBatch>(m_d3dContext.Get());
	m_states = std::make_unique<CommonStates>(m_d3dDevice.Get());
	m_fxFactory = std::make_unique<EffectFactory>(m_d3dDevice.Get());
	dynamic_cast<EffectFactory*>(m_fxFactory.get())->SetSharing(false);
	
	LoadMazeAssets();
	LoadMaze();
}

void Game::CreateResources()
{
    ID3D11RenderTargetView* nullViews [] = { nullptr };
    m_d3dContext->OMSetRenderTargets(_countof(nullViews), nullViews, nullptr);
    m_renderTargetView.Reset();
    m_depthStencilView.Reset();
    m_d3dContext->Flush();

    UINT backBufferWidth = static_cast<UINT>(m_outputWidth);
    UINT backBufferHeight = static_cast<UINT>(m_outputHeight);
    DXGI_FORMAT backBufferFormat = DXGI_FORMAT_B8G8R8A8_UNORM;
    DXGI_FORMAT depthBufferFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
    UINT backBufferCount = 2;

    if (m_swapChain)
    {
        HRESULT hr = m_swapChain->ResizeBuffers(backBufferCount, backBufferWidth, backBufferHeight, backBufferFormat, 0);

        if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
        {
            OnDeviceLost();
            return;
        }
        else
        {
            DX::ThrowIfFailed(hr);
        }
    }
    else
    {

        ComPtr<IDXGIDevice1> dxgiDevice;
        DX::ThrowIfFailed(m_d3dDevice.As(&dxgiDevice));

        ComPtr<IDXGIAdapter> dxgiAdapter;
        DX::ThrowIfFailed(dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf()));

        ComPtr<IDXGIFactory2> dxgiFactory;
        DX::ThrowIfFailed(dxgiAdapter->GetParent(IID_PPV_ARGS(dxgiFactory.GetAddressOf())));

        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
        swapChainDesc.Width = backBufferWidth;
        swapChainDesc.Height = backBufferHeight;
        swapChainDesc.Format = backBufferFormat;
        swapChainDesc.SampleDesc.Count = 1;
        swapChainDesc.SampleDesc.Quality = 0;
        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDesc.BufferCount = backBufferCount;

        DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsSwapChainDesc = {};
        fsSwapChainDesc.Windowed = TRUE;

        DX::ThrowIfFailed(dxgiFactory->CreateSwapChainForHwnd(
            m_d3dDevice.Get(),
            m_window,
            &swapChainDesc,
            &fsSwapChainDesc,
            nullptr,
            m_swapChain.ReleaseAndGetAddressOf()
            ));

        DX::ThrowIfFailed(dxgiFactory->MakeWindowAssociation(m_window, DXGI_MWA_NO_ALT_ENTER));
    }

    ComPtr<ID3D11Texture2D> backBuffer;
    DX::ThrowIfFailed(m_swapChain->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf())));

    DX::ThrowIfFailed(m_d3dDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, m_renderTargetView.ReleaseAndGetAddressOf()));

    CD3D11_TEXTURE2D_DESC depthStencilDesc(depthBufferFormat, backBufferWidth, backBufferHeight, 1, 1, D3D11_BIND_DEPTH_STENCIL);

    ComPtr<ID3D11Texture2D> depthStencil;
    DX::ThrowIfFailed(m_d3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf()));

    CD3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc(D3D11_DSV_DIMENSION_TEXTURE2D);
    DX::ThrowIfFailed(m_d3dDevice->CreateDepthStencilView(depthStencil.Get(), &depthStencilViewDesc, m_depthStencilView.ReleaseAndGetAddressOf()));
	
    
	m_Camera = std::make_unique<Camera>(m_StartPosition, SimpleMath::Vector3(0, 0, 0),
		float(backBufferWidth) / float(backBufferHeight), backBufferWidth, backBufferHeight);

	m_FontPos.x = backBufferWidth / 2.0f;
	m_FontPos.y = backBufferHeight / 2.0f;
}

void Game::OnDeviceLost()
{
    m_depthStencilView.Reset();
    m_renderTargetView.Reset();
    m_swapChain.Reset();
    m_d3dContext.Reset();
    m_d3dDevice.Reset();
	m_states.reset();
	m_fxFactory.reset();	
	m_AssetManager.Reset();

	m_Font.reset();
    CreateDevice();

    CreateResources();
}

void Game::LoadMazeAssets()
{
	m_AssetManager.RegisterModel(m_d3dDevice.Get(), L"MazeWall.cmo", *m_fxFactory, Entity::EntityTag::Wall);
	m_AssetManager.RegisterModel(m_d3dDevice.Get(), L"EndBox.cmo", *m_fxFactory, Entity::EntityTag::End);
	m_AssetManager.RegisterModel(m_d3dDevice.Get(), L"MazeFloor.cmo", *m_fxFactory, Entity::EntityTag::Floor);
}

void Game::LoadMaze()
{
	int rows = m_Maze.getRows();
	int cols = m_Maze.getCols();
	std::vector<std::vector<int>> maze = m_Maze.getMaze();


	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (maze[row][col] == 1)
			{
				Wall* temp = m_Walls.GetNext();
				temp->SetPosition(row, col);
				temp->SetModel(m_AssetManager.GetModel(Entity::EntityTag::Wall));
				m_CollidableEntities.push_back(temp);
			}
			else if (maze[row][col] == 3)
			{
				EndPoint *epPtr = new EndPoint(row, col);
				epPtr->SetModel(m_AssetManager.GetModel(Entity::EntityTag::End));
				m_CollidableEntities.push_back(epPtr);
			}
		}
	}
	m_Floor = std::make_unique<Floor>();
	m_Floor->SetModel(m_AssetManager.GetModel(Entity::EntityTag::Floor));
	m_Floor->SetPosition(Vector3(cols / 2 * 6, -8, rows * 8));
}

void Game::ResetGame()
{
	for (int i = m_CollidableEntities.size()-1; i >= 0 ; --i)
	{
		if(m_CollidableEntities[i]->GetTag() == Entity::EntityTag::Wall)
		{
			m_Walls.Return((Wall*)m_CollidableEntities[i]);
		}
		
		m_CollidableEntities.erase(m_CollidableEntities.begin() + i);
	}

	m_Maze.NewMaze(11);
	m_StartPosition = m_Maze.getStartPosition();

	LoadMaze();

	m_Camera->SetPosition(m_StartPosition);
	m_GameEnd = false;
	m_Collision = false;
}