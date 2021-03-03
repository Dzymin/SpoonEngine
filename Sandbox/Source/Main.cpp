#include <Windows.h>
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Spoon::Log::Init();

	Spoon::WindowCreateInfo createInfo = { 600, 600, 1024, 1024, L"It Works!"};
	Spoon::RefPtr<Spoon::Window> window = Spoon::Window::Create(createInfo);

	while (!window->ShouldClose());
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}


	return 0;
}