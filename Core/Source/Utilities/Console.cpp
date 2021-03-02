#include "spch.h"
#include "Console.h"

#ifdef SP_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsConsole.h"
#endif 

namespace Spoon
{
	RefPtr<Console> Console::Create()
	{
		#ifdef SP_PLATFORM_WINDOWS
			return CreateRef<WindowsConsole>();
		#else
			SP_ASSERT(false);
			return nullptr;
		#endif

	}
}