#include "spch.h"
#include "Window.h"

#ifdef SP_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Spoon
{
	ScopePtr<Window> Window::Create(const WindowCreateInfo& createInfo)
	{
		#ifdef SP_PLATFORM_WINDOWS
			return CreateScope<WindowsWindow>(createInfo);
		#endif 

	}
}