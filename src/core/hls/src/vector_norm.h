#ifndef VECTOR_NORM_H
#define VECTOR_NORM_H

const static short HIST_SIZE=16;

#include <hls_stream.h>

#include "typeDoublesFunc.h"

#define l2norm(histIN, histOUT) l2norm_mock(histIN, histOUT, timeClock, scale2_return, scale2_expect, scale2_callTime, scale2_callCount, scale2_failCount, scale2_fails)

float sum_hist_pow(float histIN[HIST_SIZE]);
#pragma DOUBLE FUNC scale2
float scale2(float sum);
void mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE]);
//void l2norm(float histIN[HIST_SIZE], float histOUT[HIST_SIZE]);

void l2norm_mock(float histIN[HIST_SIZE], float histOUT[HIST_SIZE],
		 hls::stream<unsigned int> &timeClock, 
		 hls::stream<tSCALE2_RETURN> &scale2_return,
		 hls::stream<tSCALE2_PARAM> &scale2_expect,
		 hls::stream<unsigned int> &scale2_callTime,
		 unsigned int &scale2_callCount,
		 unsigned int &scale2_failCount,
		 hls::stream<tSCALE2_FAIL> &scale2_fails);

#endif
