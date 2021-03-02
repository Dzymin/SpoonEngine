#include <Windows.h>
#include "Core.h"
#include "Utilities/Console.h"
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Spoon::RefPtr<Spoon::Console> console = Spoon::Console::Create();
	//console->RedirectIO();
	while (true)
	{
		std::cout << "JD" << std::endl;
	}
	//console->ReleaseIO();
	return 0;
}