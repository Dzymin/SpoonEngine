#pragma once
#include "Common.h"
#include "Window.h"

namespace Spoon
{
	class Engine
	{
	public:
		bool Init();
		void Run();
		void Shutdown();

	private:
		ScopePtr<Window> m_MainWindow;
	};
}