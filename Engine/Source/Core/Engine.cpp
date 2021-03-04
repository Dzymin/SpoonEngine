#include "spch.h"
#include "Engine.h"
#include "MessagePump.h"

namespace Spoon
{
	bool Engine::Init()
	{
		Log::Init();

		WindowCreateInfo createInfo = {};
		createInfo.x = 200;
		createInfo.y = 200;
		createInfo.width = 1024;
		createInfo.height = 720;
		createInfo.caption = L"Main Window";
		m_MainWindow = Window::Create(createInfo);
		
		if (m_MainWindow->GetNativeHandle() == nullptr)
		{
			return false;
			SP_CORE_CRITICAL("Failed to initilize the engine. Failed to create main window.");
		}

		return true;
	}
	
	void Engine::Run()
	{
		while (!m_MainWindow->ShouldClose())
		{
			MessagePump();
		}
	}
	
	void Engine::Shutdown()
	{
		//Manually deallocate heap allocated objects
		m_MainWindow.reset();
	}
}