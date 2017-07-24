#include "wrapper_DOUBLE_SCALE2.h"

#include "hls_casting.h"


///////////////////////////////////////////////////////////////////////
//                  Function:   return
//////////////////////////////////////////////////////////////////////
void
running_DOUBLE_SCALE2_return(hls::stream<unsigned int> &src, hls::stream<tSCALE2_RETURN> &scale2_return)
{
  readParameters_DOUBLE_SCALE2_return(src);
  //  scale2_return.write(args_DOUBLE_SCALE2_return.a);
  scale2_return.write(args_DOUBLE_SCALE2_return); 
}


void
readParameters_DOUBLE_SCALE2_return(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_DOUBLE_SCALE2_return)/sizeof(int)];

  for(int it=0; it != sizeof(args_DOUBLE_SCALE2_return)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  args_DOUBLE_SCALE2_return._return = toFloat(*ptr++);  
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   expect
//////////////////////////////////////////////////////////////////////
void
running_DOUBLE_SCALE2_expect(hls::stream<unsigned int> &src, hls::stream<tSCALE2_PARAM> &scale2_expect)
{
  readParameters_DOUBLE_SCALE2_expect(src);
  scale2_expect.write(args_DOUBLE_SCALE2_expect); 
}


void
readParameters_DOUBLE_SCALE2_expect(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_DOUBLE_SCALE2_expect)/sizeof(int)];

  for(int it=0; it != sizeof(args_DOUBLE_SCALE2_expect)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  args_DOUBLE_SCALE2_expect.sum = toFloat(*ptr++);  
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   callCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_DOUBLE_SCALE2_callCount{
  unsigned int words32[sizeof(ret_DOUBLE_SCALE2_callCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_DOUBLE_SCALE2_callCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_DOUBLE_SCALE2_callCount)];
}byteRet_DOUBLE_SCALE2_callCount;


void
running_DOUBLE_SCALE2_callCount(hls::stream<unsigned int> &dst, unsigned int &scale2_callCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = scale2_callCount;
  byteRet_DOUBLE_SCALE2_callCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_DOUBLE_SCALE2_callCount.words32)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_DOUBLE_SCALE2_callCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failCount
//////////////////////////////////////////////////////////////////////
union UNION_RET_DOUBLE_SCALE2_failCount{
  unsigned int words32[sizeof(ret_DOUBLE_SCALE2_failCount)/sizeof(int)];
  unsigned short words16[sizeof(ret_DOUBLE_SCALE2_failCount)/sizeof(short)];
  unsigned char words8[sizeof(ret_DOUBLE_SCALE2_failCount)];
}byteRet_DOUBLE_SCALE2_failCount;


void
running_DOUBLE_SCALE2_failCount(hls::stream<unsigned int> &dst, unsigned int &scale2_failCount)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = scale2_failCount;
  byteRet_DOUBLE_SCALE2_failCount.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_DOUBLE_SCALE2_failCount.words32)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_DOUBLE_SCALE2_failCount.words32[itReturn]);
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   callTime
//////////////////////////////////////////////////////////////////////
union UNION_RET_DOUBLE_SCALE2_callTime{
  unsigned int words32[sizeof(ret_DOUBLE_SCALE2_callTime)/sizeof(int)];
  unsigned short words16[sizeof(ret_DOUBLE_SCALE2_callTime)/sizeof(short)];
  unsigned char words8[sizeof(ret_DOUBLE_SCALE2_callTime)];
}byteRet_DOUBLE_SCALE2_callTime;


void
running_DOUBLE_SCALE2_callTime(hls::stream<unsigned int> &dst, hls::stream<unsigned int> &scale2_callTime)
{
  short index = 0;
  unsigned int ptr_return;
  ptr_return = scale2_callTime.read();
  //ptr_return = (&scale2_callTime+scale2_callTime_rd_index);
  byteRet_DOUBLE_SCALE2_callTime.words32[index++] = ptr_return;

  for(int itReturn=0; itReturn != sizeof(byteRet_DOUBLE_SCALE2_callTime.words32)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_DOUBLE_SCALE2_callTime.words32[itReturn]);

  //  scale2_callTime_rd_index += 1;
}
///////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
//                  Function:   failures
//////////////////////////////////////////////////////////////////////
union UNION_RET_DOUBLE_SCALE2_failures{
  unsigned int words32[sizeof(ret_DOUBLE_SCALE2_failures)/sizeof(int)];
  unsigned short words16[sizeof(ret_DOUBLE_SCALE2_failures)/sizeof(short)];
  unsigned char words8[sizeof(ret_DOUBLE_SCALE2_failures)];
}byteRet_DOUBLE_SCALE2_failures;


void
running_DOUBLE_SCALE2_failures(hls::stream<unsigned int> &dst, hls::stream<tSCALE2_FAIL> &scale2_failures)
{
  short index = 0;
  tSCALE2_FAIL auxFail;

  auxFail = scale2_failures.read();


  unsigned int ptr_callCount;
  ptr_callCount = auxFail._callCount;
  byteRet_DOUBLE_SCALE2_failures.words32[index++] = ptr_callCount;

  unsigned int ptr_time;
  ptr_time = auxFail._time;
  byteRet_DOUBLE_SCALE2_failures.words32[index++] = ptr_time;

  tSCALE2_PARAM auxExpect;
  auxExpect = auxFail._expect;
  unsigned int ptr_expect_sum[1];
  toSequence(auxExpect.sum, ptr_expect_sum);
  byteRet_DOUBLE_SCALE2_failures.words32[index++] = ptr_expect_sum[0];

  tSCALE2_PARAM auxParam;
  auxParam = auxFail._param;
  unsigned int ptr_param_sum[1];
  toSequence(auxParam.sum, ptr_param_sum);
  byteRet_DOUBLE_SCALE2_failures.words32[index++] = ptr_param_sum[0];

  for(int itReturn=0; itReturn != sizeof(byteRet_DOUBLE_SCALE2_failures.words32)/DOUBLE_SCALE2_BUS_WIDTH_BYTES; itReturn++)  
    dst.write(byteRet_DOUBLE_SCALE2_failures.words32[itReturn]);

  // scale2_failures_rd_index += 1;
}
///////////////////////////////////////////////////////////////////////

