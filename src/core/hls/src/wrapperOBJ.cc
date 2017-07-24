#include "wrapperOBJ.h"

#include "hls_casting.h"


///////////////////////////////////////////////////////////////////////
//                  Function:   l2norm
//////////////////////////////////////////////////////////////////////
union UNION_RET_OBJ_l2norm{
  unsigned int words32[sizeof(ret_OBJ_l2norm)/sizeof(int)];
  unsigned short words16[sizeof(ret_OBJ_l2norm)/sizeof(short)];
  unsigned char words8[sizeof(ret_OBJ_l2norm)];
}byteRet_OBJ_l2norm;


// void
// testing_OBJ_l2norm(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst)
// {
//   int ret;
//   readParameters_OBJ_l2norm(src);
//   l2norm(args_OBJ_l2norm.histIN, ret_OBJ_l2norm.histOUT);
//   writeReturn_OBJ_l2norm(dst);
// }


void 
testing_OBJ_l2norm_mock(hls::stream<unsigned int> &src, hls::stream<unsigned int> &dst,
			hls::stream<unsigned int> &timeClock, 
			hls::stream<tSCALE2_RETURN> &scale2_return,
			hls::stream<tSCALE2_PARAM> &scale2_expect,
			hls::stream<unsigned int> &scale2_callTime,
			unsigned int &scale2_callCount,
			unsigned int &scale2_failCount,
			hls::stream<tSCALE2_FAIL> &scale2_failures)
{  
  readParameters_OBJ_l2norm(src);
  l2norm(args_OBJ_l2norm.histIN, ret_OBJ_l2norm.histOUT);
  writeReturn_OBJ_l2norm(dst);  
}



void
readParameters_OBJ_l2norm(hls::stream<unsigned int> &src)
{ 
  int words32[sizeof(args_OBJ_l2norm)/sizeof(int)];

  for(int it=0; it != sizeof(args_OBJ_l2norm)/OBJ_BUS_WIDTH_BYTES; it++)
    words32[it] = src.read();
  
  // Casting
  unsigned int *ptr= (unsigned int*)words32;  
  for(int it=0; it != HIST_SIZE; it++)
    args_OBJ_l2norm.histIN[it] = toFloat(*ptr++);
}


void
writeReturn_OBJ_l2norm(hls::stream<unsigned int> &dst)
{ 
  short index=0;


  unsigned int ptr_histOUT[sizeof(ret_OBJ_l2norm.histOUT[0])/OBJ_L2NORM_WRITE_SIZE_BYTES];
  for(int it_histOUT=0; it_histOUT != sizeof(ret_OBJ_l2norm.histOUT)/sizeof(ret_OBJ_l2norm.histOUT[0]); it_histOUT++){  
    toSequence(ret_OBJ_l2norm.histOUT[it_histOUT], ptr_histOUT);
    for(int it=0; it!=sizeof(ret_OBJ_l2norm.histOUT[0])/OBJ_L2NORM_WRITE_SIZE_BYTES; it++) 
      byteRet_OBJ_l2norm.words32[index++] = ptr_histOUT[it];
  }

  for(int itReturn=0; itReturn != sizeof(byteRet_OBJ_l2norm.words32)/4; itReturn++)  
    dst.write(byteRet_OBJ_l2norm.words32[itReturn]); 
}
///////////////////////////////////////////////////////////////////////

