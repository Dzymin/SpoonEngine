#pragma once
#include "Core/Window.h"

namespace Spoon
{
	struct WindowData 
	{
		int32 x;
		int32 y;
		int32 width;
		int32 height;
		const wchar_t* caption;
		bool shouldClose;
	};
	
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowCreateInfo& createInfo);
		virtual ~WindowsWindow() = default;

		int32 GetWidth() const override;
		int32 GetHeight() const override;
		int32 GetXPos() const override;
		int32 GetYPos() const override;
		std::pair<int32, int32> GetPos() const override;
		bool ShouldClose() const override;
		void* GetNativeHandle() const override;

	private:
		HWND m_Handle;

		WindowData m_Data;
	};
}