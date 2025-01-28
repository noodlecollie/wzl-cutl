#include "wzl_cutl/time.h"
#include "wzl_cutl_/windows/winapi_min.h"
#include <sysinfoapi.h>

WZL_CUTL_PUBLIC(int32_t) wzl_get_milliseconds_modulo(void)
{
	SYSTEMTIME time;
	GetSystemTime(&time);
	return (int32_t)time.wMilliseconds;
}

WZL_CUTL_PUBLIC(uint64_t) wzl_get_milliseconds_monotonic(void)
{
	return (uint64_t)GetTickCount64();
}
