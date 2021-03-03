#pragma once
#include "Core/Window.h"

namespace Spoon
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowCreateInfo& createInfo);
		virtual ~WindowsWindow() = default;

		bool ShouldClose() const override;
		void* GetNativeHandle() const override;

	private:
		HWND m_Handle;

		struct WindowData {
			int32 x;
			int32 y;
			int32 width;
			int32 height;
			const wchar_t* caption;
			bool shouldClose;
		} m_Data;
	};
}