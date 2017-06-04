#ifndef TOPTESTING_H
#define TOPTESTING_H

#include "header.h"

#include <hls_stream.h>
#include "typeDoublesFunc.h"


static struct headerStruct header_OBJ;

static hls::stream<unsigned int> bufferIN_OBJ;
static hls::stream<unsigned int> bufferOUT_OBJ;
static hls::stream<unsigned int> bufferRESP_OBJ;

static hls::stream<tSCALE2_RETURN> scale2_return;
static hls::stream<tSCALE2_PARAM> scale2_expect;
static hls::stream<unsigned int> scale2_callTime;
static hls::stream<tSCALE2_FAIL> scale2_fails;
static unsigned int scale2_callCount = 0;
static unsigned int scale2_failCount = 0;

void inputBuffer_OBJ(hls::stream<unsigned int> &src);
void outputBuffer_OBJ(hls::stream<unsigned int> &dst);
void forward_OBJ(short size);

void getRequestHead_OBJ();
void buildResponseHead_OBJ(hls::stream<unsigned int> &dst,
		       unsigned short objID, unsigned short size, 
		       unsigned char flags);
void
buildResponse_OBJ(unsigned short objID, unsigned short size,
		  unsigned char flags);

void topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout,
		hls::stream<unsigned int> timeClock);
void manager_OBJ(hls::stream<unsigned int> &timeClock);

#endif
