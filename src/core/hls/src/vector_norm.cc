// -*- coding: utf-8; mode: c++; tab-width: 4 -*-

#include "vector_norm.h"
#include <cmath>

#include "hls_math.h"

#include "scale2_mock.h"

static float histAUX_1 [HIST_SIZE];

float
sum_hist_pow(float histIN[HIST_SIZE])
{
  float sum = 0.f;
  float inAUX;

  inAUX = histIN[0];
 loop1:for(int i = 0; i != HIST_SIZE; i++){
	sum += inAUX*inAUX;	  
	histAUX_1[i] = inAUX;
    if (i < HIST_SIZE-1)
      inAUX = histIN[i+1];
  }
  return sum;
}


void
mult_hist_scale(float histAUX[HIST_SIZE], float scale, float histOUT[HIST_SIZE])
{
 loop2:for(int i = 0; i != HIST_SIZE; i++)
    histOUT[i] = histAUX[i]*scale;
}


// void
// l2norm(float histIN[HIST_SIZE], float histOUT[HIST_SIZE])
void l2norm_mock(float histIN[HIST_SIZE], float histOUT[HIST_SIZE],
				 hls::stream<unsigned int> &timeClock, 
				 hls::stream<tSCALE2_RETURN> &scale2_return,
				 hls::stream<tSCALE2_PARAM> &scale2_expect,
				 hls::stream<unsigned int> &scale2_callTime,
				 unsigned int &scale2_callCount,
				 unsigned int &scale2_failCount,
				 hls::stream<tSCALE2_FAIL> &scale2_failures)
{
  float scale = 0.f;
  float sum = 0.f;
  
  sum = sum_hist_pow(histIN);
  scale = scale2(sum);
  mult_hist_scale(histAUX_1, scale, histOUT);
}


