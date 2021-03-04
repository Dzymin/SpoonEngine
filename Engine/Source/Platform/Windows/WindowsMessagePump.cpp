#include "spch.h"
#include "Core/MessagePump.h"

namespace Spoon
{
	void MessagePump()
	{
		MSG msg = {};
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}