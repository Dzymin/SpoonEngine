#include <Windows.h>
#include "Core.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Spoon::Log::Init();

	Spoon::WindowCreateInfo createInfo = { 700, 100, 720, 480, L"Spoon Game" };
	Spoon::WindowCreateInfo createInfo2 = { 100, 100, 720, 480, L"Spoon Game 2" };
	Spoon::RefPtr<Spoon::Window> window = Spoon::Window::Create(createInfo);
	Spoon::RefPtr<Spoon::Window> window2 = Spoon::Window::Create(createInfo2);

	while (!window->ShouldClose() || !window2->ShouldClose())
	{
		MSG msg = {};
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}


	return 0;
}