#include "spch.h"
#include "Window.h"

#ifdef SP_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Spoon
{
	RefPtr<Window> Window::Create(const WindowCreateInfo& createInfo)
	{
		#ifdef SP_PLATFORM_WINDOWS
			return CreateRef<WindowsWindow>(createInfo);
		#endif 

	}
}