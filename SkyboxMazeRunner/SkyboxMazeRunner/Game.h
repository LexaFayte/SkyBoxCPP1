//
// Game.h
//

#pragma once

#include "StepTimer.h"
#include "Camera.h"
#include "MazeMaker.h"
#include "ObjectPool.h"
#include "AssetManager.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();
	void ProcessCollisions();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

	void LoadMazeAssets();
	void LoadMaze();
	void ResetGame();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;

    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	AssetManager m_AssetManager;
	std::unique_ptr<DirectX::CommonStates> m_states;
	std::unique_ptr<DirectX::IEffectFactory> m_fxFactory;

	std::unique_ptr<DirectX::Keyboard> m_keyboard;
	std::unique_ptr<DirectX::Mouse> m_mouse;
	std::unique_ptr<DirectX::GamePad> m_GamePad;
	std::unique_ptr<DirectX::SpriteFont> m_Font;
	std::unique_ptr<Camera> m_Camera;

	SimpleMath::Vector2 m_FontPos;
	std::unique_ptr<DirectX::SpriteBatch> m_SpriteBatch;


	ObjectPool<Wall*> m_Walls;
	MazeMaker m_Maze;
	const std::string k_MazeFileName = "TestMaze.txt";

	std::vector<Entity*> m_Entities;
	DirectX::Model m_MazeFloor;
	SimpleMath::Vector3 m_FloorPosition;

	SimpleMath::Vector3 m_StartPosition = SimpleMath::Vector3::Zero;
	bool mCollisionsEnabled = true;
	bool m_Collision = false;
	bool m_GameEnd = false;
};