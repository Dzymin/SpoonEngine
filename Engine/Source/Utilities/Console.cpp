#include "spch.h"
#include "Console.h"

#ifdef SP_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsConsole.h"
#endif 

namespace Spoon
{
	ScopePtr<Console> Console::Create()
	{
		#ifdef SP_PLATFORM_WINDOWS
			return CreateScope<WindowsConsole>();
		#else
			SP_ASSERT(false);
			return nullptr;
		#endif

	}
}