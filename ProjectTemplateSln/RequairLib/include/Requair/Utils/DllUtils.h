#pragma once

#ifdef _WIN32

	//RequairDLL_EXPORTS
	#ifdef Requair_EXPORTS 
		#define libRequair __declspec(dllexport)
	#else
		#define libRequair __declspec(dllimport)
	#endif
	#ifdef debugDefines
		#ifdef Requair_EXPORTS 
			#define libPvtRequair __declspec(dllexport)
		#else
			#define libPvtRequair __declspec(dllimport)
		#endif
	#else
		#define libPvtRequair
	#endif
#else
	#define libRequair
	#define libPvtRequair
#endif
