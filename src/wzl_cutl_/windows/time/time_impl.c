#include "wzl_cutl/time.h"
#include "wzl_cutl_/windows/winapi_min.h"

WZL_CUTL_PUBLIC(int32_t) wzl_get_milliseconds_modulo(void)
{
	SYSTEMTIME time;
	GetSystemTime(&time);
	return (int32_t)time.wMilliseconds;
}
