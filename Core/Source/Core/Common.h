#pragma once

#ifdef SP_DEBUG
	#if defined(SP_TOOLSET_MSVC)
		#define SP_DEBUGBREAK() __debugbreak()
	#else
		#error "This toolset doesn't support debugbreak yet!"
	#endif

	#define SP_ENABLE_ASSERTS
#else
	#define SP_DEBUGBREAK()
#endif 

#ifdef SP_ENABLE_ASSERTS
	#define SP_ASSERT(check) if(!(check)) { SP_DEBUGBREAK(); } //TODO: add error logging;
#else
	#define SP_ASSERT(check)
#endif 


namespace Spoon
{
	using int8 = __int8;
	using int16 = __int16;
	using int32 = __int32;
	using int64 = __int64;
	
	using uint8 = unsigned __int8;
	using uint16 = unsigned __int16;
	using uint32 = unsigned __int32;
	using uint64 = unsigned __int64;
}
