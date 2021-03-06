#pragma once
#include "Core/Common.h"

namespace Spoon
{
	class Console
	{
	public:
		virtual ~Console() = default;

		static ScopePtr<Console> Create();
	};
}