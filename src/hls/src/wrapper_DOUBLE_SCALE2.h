#ifndef WRAPPER_DOUBLE_SCALE2_H
#define WRAPPER_DOUBLE_SCALE2_H

//#include <ap_int.h>
#include <hls_stream.h>
#include "typeDoublesFunc.h"

const int DOUBLE_SCALE2_BUS_WIDTH_BYTES = 4; //int

static char ID_DOUBLE_SCALE2=2;


///////////////////////////////////////////////////////////////////////
//                 Function:   return
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_return = 1;
static unsigned char ID_DOUBLE_SCALE2_return = 1;

//static int scale2_return[32];
//static char scale2_return_index = 0;

//const int DOUBLE_SCALE2_RETURN_READ_SIZE_BYTES = 4; //int


/* struct PARAM_DOUBLE_SCALE2_return{ */
/*   int _return; */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


/* static struct PARAM_DOUBLE_SCALE2_return  args_DOUBLE_SCALE2_return; */
static tSCALE2_RETURN  args_DOUBLE_SCALE2_return;

void running_DOUBLE_SCALE2_return(hls::stream<unsigned int> &src, hls::stream<tSCALE2_RETURN> &scale2_return);
void readParameters_DOUBLE_SCALE2_return(hls::stream<unsigned int> &src);
//////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
//                 Function:   expect
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_expect = 2;
static unsigned char ID_DOUBLE_SCALE2_expect = 2;

//static int scale2_expect[32];
//static char scale2_expect_index = 0;

//const int DOUBLE_SCALE2_RETURN_READ_SIZE_BYTES = 4; //int


/* struct PARAM_DOUBLE_SCALE2_expect{ */
/*   int a; */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


/* #static struct PARAM_DOUBLE_SCALE2_expect  args_DOUBLE_SCALE2_expect; */
static tSCALE2_PARAM  args_DOUBLE_SCALE2_expect;


void running_DOUBLE_SCALE2_expect(hls::stream<unsigned int> &src, hls::stream<tSCALE2_PARAM> &scale2_expect);
void readParameters_DOUBLE_SCALE2_expect(hls::stream<unsigned int> &src);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   callCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_callCount = 3;
static unsigned char ID_DOUBLE_SCALE2_callCount = 3;

//static int scale2_callCount = 0;

//const int DOUBLE_SCALE2_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_DOUBLE_SCALE2_callCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_DOUBLE_SCALE2_callCount ret_DOUBLE_SCALE2_callCount;

void running_DOUBLE_SCALE2_callCount(hls::stream<unsigned int> &dst, unsigned int &scale2_callCount);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   failCount
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_failCount = 4;
static unsigned char ID_DOUBLE_SCALE2_failCount = 4;

//static int scale2_failCount = 0;

//const int DOUBLE_SCALE2_CALLCOUNT_WRITE_SIZE_BYTES = 4; //int

struct RETURN_DOUBLE_SCALE2_failCount{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_DOUBLE_SCALE2_failCount ret_DOUBLE_SCALE2_failCount;

void running_DOUBLE_SCALE2_failCount(hls::stream<unsigned int> &dst, unsigned int &scale2_failCount);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   callTime
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_callTime = 5;
static unsigned char ID_DOUBLE_SCALE2_callTime = 5;

//static char scale2_callTime_rd_index = 0;

//const int DOUBLE_SCALE2_CALLTIME_WRITE_SIZE_BYTES = 4; //int

struct RETURN_DOUBLE_SCALE2_callTime{
  unsigned int _return;
  // here padding if its necessary
}__attribute__((packed));

static struct RETURN_DOUBLE_SCALE2_callTime ret_DOUBLE_SCALE2_callTime;

void running_DOUBLE_SCALE2_callTime(hls::stream<unsigned int> &dst, hls::stream<unsigned int> &scale2_callTime);
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                 Function:   fails
//////////////////////////////////////////////////////////////////////
//static ap_int<12> ID_DOUBLE_SCALE2_fails = 6;
static unsigned char ID_DOUBLE_SCALE2_fails = 6;

//const int DOUBLE_SCALE2_CALLTIME_WRITE_SIZE_BYTES = 4; //int

/* struct RETURN_DOUBLE_SCALE2_fails{ */
/*   int _callCount; */
/*   tSCALE2_PARAM _param; */
/*   tSCALE2_PARAM _expect; */
/*   int _time; */
/*   // here padding if its necessary */
/* }__attribute__((packed)); */


//static tSCALE2_FAIL scale2_fails[32];
static char scale2_fails_rd_index = 0;

//static struct RETURN_DOUBLE_SCALE2_fails ret_DOUBLE_SCALE2_fails;
static tSCALE2_FAIL ret_DOUBLE_SCALE2_fails;

//void running_DOUBLE_SCALE2_fails(hls::stream<unsigned int> &dst);//, hls::stream<tfail> &scale2_fails);
void running_DOUBLE_SCALE2_fails(hls::stream<unsigned int> &dst, hls::stream<tSCALE2_FAIL> &scale2_fails);
//////////////////////////////////////////////////////////////////////

#endif
