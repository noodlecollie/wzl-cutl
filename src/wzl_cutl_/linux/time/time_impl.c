#include <bits/time.h>
#include <time.h>
#include "wzl_cutl/time.h"

WZL_CUTL_PUBLIC(int32_t) wzl_get_milliseconds_modulo(void)
{
	struct timespec tms;

	if ( clock_gettime(CLOCK_REALTIME, &tms) )
	{
		return -1;
	}

	return (int32_t)(tms.tv_nsec / 1000000);
}

WZL_CUTL_PUBLIC(uint64_t) wzl_get_milliseconds_monotonic(void)
{
	struct timespec tms;

	if ( clock_gettime(CLOCK_MONOTONIC, &tms) )
	{
		return 0;
	}

	return (tms.tv_sec * 1000) + (tms.tv_nsec / 1000000);
}
