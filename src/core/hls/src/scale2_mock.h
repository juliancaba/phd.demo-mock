#ifndef SCALE2_MOCK_H
#define SCALE2_MOCK_H

#include "typeDoublesFunc.h"
#include <hls_stream.h>

#define scale2(sum) scale2_mock(timeClock, scale2_return, scale2_expect, scale2_callTime, scale2_callCount, scale2_failCount, scale2_failures, sum)

float scale2_mock(hls::stream<unsigned int> &timeClock, 
		  hls::stream<tSCALE2_RETURN> &scale2_return,
		  hls::stream<tSCALE2_PARAM> &scale2_expect,
		  hls::stream<unsigned int> &scale2_callTime,
		  unsigned int &scale2_callCount,
		  unsigned int &scale2_failCount,
		  hls::stream<tSCALE2_FAIL> &scale2_failures,
		  float sum);

#endif
