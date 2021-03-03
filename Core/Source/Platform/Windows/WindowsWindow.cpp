#include "spch.h"
#include "WindowsWindow.h"

namespace Spoon
{
	LRESULT WINAPI internalWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	WindowsWindow::WindowsWindow(const WindowCreateInfo& createInfo)
	{
		m_Data.x = createInfo.x;
		m_Data.y = createInfo.y;
		m_Data.width = createInfo.width;
		m_Data.height = createInfo.height;
		m_Data.caption = createInfo.caption;
		m_Data.shouldClose = false;

		WNDCLASSEX wc = {};
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.style = CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = internalWindowProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = nullptr;
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = L"Spoon Window";
		wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

		RegisterClassEx(&wc);

		RECT wndRect = { 0, 0, m_Data.width, m_Data.height };
		AdjustWindowRect(&wndRect, WS_OVERLAPPEDWINDOW, FALSE);
		int32 width = wndRect.right - wndRect.left;
		int32 height = wndRect.bottom - wndRect.top;

		m_Handle = CreateWindowEx(0, wc.lpszClassName, m_Data.caption, WS_OVERLAPPEDWINDOW, m_Data.x, m_Data.y, width, height, nullptr, nullptr, nullptr, &m_Data);
		if (!m_Handle)
		{
			SP_CORE_ERROR("Failed to create window");
		}

		ShowWindow(m_Handle, SW_SHOWNORMAL);
		UpdateWindow(m_Handle);
	}
	
	bool WindowsWindow::ShouldClose() const
	{
		return m_Data.shouldClose;
	}
	
	void* WindowsWindow::GetNativeHandle() const
	{
		return m_Handle;
	}
}