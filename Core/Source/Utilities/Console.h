#pragma once
#include "Core/Common.h"

namespace Spoon
{
	class Console
	{
	public:
		virtual ~Console() = default;

		static RefPtr<Console> Create();

		virtual void RedirectIO() = 0;
		virtual void ReleaseIO() = 0;
	};
}