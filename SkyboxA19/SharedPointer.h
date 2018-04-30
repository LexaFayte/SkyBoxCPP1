#pragma once
namespace smrt_ptr
{
	template<class T>
	class ControlBlock
	{
	private:
		T * mRawPtr = nullptr;
		int mStrongReferenceCount = 0;

		void CheckLifetime()
		{
			if (mStrongReferenceCount == 0)
			{
				this->~ControlBlock();
			}
		}
	public:
		ControlBlock<T>(T* rawPtr) : mStrongReferenceCount(0), mRawPtr(rawPtr) {};
		~ControlBlock<T>() { delete mRawPtr; };
		ControlBlock<T>(const ControlBlock& other) = delete;
		ControlBlock<T>(ControlBlock&& other) noexcept = delete;
		ControlBlock<T>& operator=(const ControlBlock& other) = delete;
		ControlBlock<T>& operator=(ControlBlock&& other) noexcept = delete;

		T* GetRaw()
		{
			return mRawPtr;
		}

		void AddReference()
		{
			++mStrongReferenceCount;
		}

		void ReleaseReference()
		{
			--mStrongReferenceCount;
			CheckLifetime();
		}
	};


	template<class T>
	class SharedPointer
	{
	private:
		ControlBlock<T>* mControlBlock;

	public:
		SharedPointer<T>() = default;
		~SharedPointer<T>()
		{
			if (mControlBlock != nullptr)
			{
				ReleaseShared();
			}
		};

		SharedPointer<T>(const SharedPointer& other)
		{
			mControlBlock = other.mControlBlock;
			mControlBlock->AddReference();
		}

		SharedPointer<T>& operator=(const SharedPointer& other)
		{
			if (this == &other)
			{
				return *this;
			}

			mControlBlock = other.mControlBlock;
			mControlBlock->AddReference();
			return *this;
		}

		template<typename...TPack>
		SharedPointer<T>& MakeShared(TPack... args);
		SharedPointer<T>& MakeShared(T* item);
		void ReleaseShared();
		T* GetRawPointer();

		friend SharedPointer<T> MakeShared(T* item);

		T& operator*() const { return *mControlBlock->GetRaw(); }
		T* operator->() const { return mControlBlock->GetRaw(); }
	};

	template<class T>
	template<typename ...TPack>
	inline SharedPointer<T>& SharedPointer<T>::MakeShared(TPack ...args)
	{
		mControlBlock = new ControlBlock<T>(new T(std::forward<TPack>(args)...));
		mControlBlock->AddReference();
		return *this;
	}

	template<class T>
	inline SharedPointer<T>& SharedPointer<T>::MakeShared(T* item)
	{
		mControlBlock = new ControlBlock<T>(item);
		mControlBlock->AddReference();
		return *this;
	}

	template<class T>
	inline void SharedPointer<T>::ReleaseShared()
	{
		mControlBlock->ReleaseReference();
		mControlBlock = nullptr;
	}

	template<class T>
	inline T* SharedPointer<T>::GetRawPointer()
	{
		return mControlBlock->GetRaw();
	}

	template<class T>
	SharedPointer<T> MakeShared(T* item)
	{
		SharedPointer<T> sp;
		sp.MakeShared(item);
		return sp;
	}
}