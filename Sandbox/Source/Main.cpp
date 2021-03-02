#include <Windows.h>
#include "Core.h"
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Spoon::Log::Init();
	SP_INFO("It works");
	while (true)
	{

	}
	return 0;
}