#include <Windows.h>
#include "SpoonEngine.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Spoon::Engine* engine = new Spoon::Engine;
	if (!engine->Init())
	{
		SP_CRITICAL("Failed to initilize the engine");
		delete engine;
		return -1;
	}
	
	engine->Run();
	engine->Shutdown();

	delete engine;
	return 0;
}