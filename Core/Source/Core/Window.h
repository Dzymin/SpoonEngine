#pragma once
#include "Common.h"

namespace Spoon
{
	struct WindowCreateInfo
	{
		int32 x;
		int32 y;
		int32 width;
		int32 height;
		const wchar_t* caption;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual int32 GetWidth() const = 0;
		virtual int32 GetHeight() const = 0;
		virtual int32 GetXPos() const = 0;
		virtual int32 GetYPos() const = 0;
		virtual std::pair<int32, int32> GetPos() const = 0;
		virtual bool ShouldClose() const = 0;
		virtual void* GetNativeHandle() const = 0;

		static RefPtr<Window> Create(const WindowCreateInfo& createInfo = WindowCreateInfo{ 0, 0, 720, 480, L"Spoon Game" });
	};
}