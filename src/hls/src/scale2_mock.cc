// -*- coding: utf-8; mode: c++; tab-width: 4 -*-

#include "scale2_mock.h"

#include <hls_math.h>

const static float DELTA = 0.00001;

float 
scale2_mock(hls::stream<unsigned int> &timeClock, 
			hls::stream<tSCALE2_RETURN> &scale2_return,
			hls::stream<tSCALE2_PARAM> &scale2_expect,
			hls::stream<unsigned int> &scale2_callTime,
			unsigned int &scale2_callCount,
			unsigned int &scale2_failCount,
			hls::stream<tSCALE2_FAIL> &scale2_fails,
			float sum)
{
#pragma HLS RESET variable=scale2_callCount
#pragma HLS RESET variable=scale2_failCount
#pragma HLS RESET variable=scale2_callTime
  //#pragma HLS RESET variable=scale2_return
  //#pragma HLS RESET variable=scale2_expect
#pragma HLS RESET variable=scale2_fails
#pragma HLS STREAM variable=scale2_return depth=32
#pragma HLS STREAM variable=scale2_expect depth=32
#pragma HLS STREAM variable=scale2_fails depth=32
  tSCALE2_FAIL auxFail;
  float _return;
  float _expect_sum;
  float _diff;
  unsigned int _time;
  

  _expect_sum = scale2_expect.read().sum;
  _time = timeClock.read();
  _diff = fabsf(sum - _expect_sum);
  
  if(_diff > DELTA){
	auxFail._callCount = scale2_callCount;
    auxFail._param.sum = sum;
    auxFail._expect.sum = _expect_sum;
    auxFail._time = _time;
	scale2_fails.write(auxFail);
    scale2_failCount += 1;
  }
  scale2_callTime.write(_time);
  _return = scale2_return.read()._return;
  scale2_callCount += 1;

  return _return;
}


