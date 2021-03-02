#include "spch.h"
#include "WindowsConsole.h"

namespace Spoon
{
	WindowsConsole::WindowsConsole()
	{
		AllocConsole();
		FILE* file;
		freopen_s(&file, "CONINT$", "r", stdin);
		freopen_s(&file, "CONOUT$", "w", stdout);
		freopen_s(&file, "CONOUT$", "w", stderr);

		std::ios::sync_with_stdio(true);

		std::wcout.clear();
		std::cout.clear();
		std::wcin.clear();
		std::cin.clear();
		std::wcerr.clear();
		std::cerr.clear();
	}
	
	WindowsConsole::~WindowsConsole()
	{
		FILE* file;
		freopen_s(&file, "NUL:", "r", stdin);
		freopen_s(&file, "NUL:", "w", stdout);
		freopen_s(&file, "NUL:", "w", stderr);

		FreeConsole();
	}
	
	void WindowsConsole::RedirectIO()
	{
		FILE* file;
		freopen_s(&file, "CONINT$", "r", stdin);
		freopen_s(&file, "CONOUT$", "w", stdout);
		freopen_s(&file, "CONOUT$", "w", stderr);

		std::ios::sync_with_stdio(true);

		std::wcout.clear();
		std::cout.clear();
		std::wcin.clear();
		std::cin.clear();
		std::wcerr.clear();
		std::cerr.clear();
	}
	
	void WindowsConsole::ReleaseIO()
	{
		FILE* file;
		freopen_s(&file, "NUL:", "r", stdin);
		freopen_s(&file, "NUL:", "w", stdout);
		freopen_s(&file, "NUL:", "w", stderr);
	}
}