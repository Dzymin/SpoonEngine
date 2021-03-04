#include "spch.h"
#include "WindowsWindow.h"

namespace Spoon
{
	LRESULT WINAPI internalWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		WindowData* data = reinterpret_cast<WindowData*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
		
		switch (msg)
		{
		case WM_CLOSE:
			data->shouldClose = true;
			DestroyWindow(hwnd);
			break;

		case WM_MOVE:
			data->x = (int32)LOWORD(lParam);
			data->y = (int32)HIWORD(lParam);
			break;

		case WM_SIZE:
			data->width = (int32)LOWORD(lParam);
			data->height = (int32)HIWORD(lParam);
			break;
		}
		
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	
	LRESULT WINAPI internalWindowProcSetup(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			CREATESTRUCT* createStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
			WindowData* data = static_cast<WindowData*>(createStruct->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(data));
			SetWindowLongPtr(hwnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&internalWindowProc));

			return internalWindowProc(hwnd, msg, wParam, lParam);
		}

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
		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		wc.lpfnWndProc = internalWindowProcSetup;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = nullptr;
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = L"SpoonWindow";
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
		else
		{
			ShowWindow(m_Handle, SW_SHOW);
			UpdateWindow(m_Handle);
		}

	}
	
	int32 WindowsWindow::GetWidth() const
	{
		return m_Data.width;
	}

	int32 WindowsWindow::GetHeight() const
	{
		return m_Data.height;
	}

	int32 WindowsWindow::GetXPos() const
	{
		return m_Data.x;
	}

	int32 WindowsWindow::GetYPos() const
	{
		return m_Data.y;
	}

	std::pair<int32, int32> WindowsWindow::GetPos() const
	{
		return std::pair<int32, int32> { m_Data.x, m_Data.y };
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