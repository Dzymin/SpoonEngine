#include "spch.h"
#include "WindowsConsole.h"

namespace Spoon
{
	WindowsConsole::WindowsConsole()
	{
		AllocConsole();
	}
	
	WindowsConsole::~WindowsConsole()
	{
		FreeConsole();
	}
}