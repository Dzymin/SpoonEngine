#pragma once
#include "Utilities/Console.h"

namespace Spoon
{
	class WindowsConsole : public Console
	{
	public:
		WindowsConsole();
		virtual ~WindowsConsole();

		void RedirectIO() override;
		void ReleaseIO() override;
	};
}