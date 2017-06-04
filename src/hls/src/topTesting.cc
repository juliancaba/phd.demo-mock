#include "topTesting.h"
#include "wrapperOBJ.h"
#include "wrapper_DOUBLE_SCALE2.h"


// union typeHead{
//   unsigned int words32;
//   unsigned char words8[4];  
// }byteHeader[2];



void
inputBuffer_OBJ(hls::stream<unsigned int> &src)
{
  unsigned int aux;
  aux = src.read();
  bufferIN_OBJ.write(aux);
}


void
outputBuffer_OBJ(hls::stream<unsigned int> &dst)
{
  unsigned int aux;
  while(!bufferOUT_OBJ.empty()){
    aux = bufferOUT_OBJ.read();
    dst.write(aux);
  }
}


void
forward_OBJ(short size)
{
  short it=0;
  while(it != size){
    bufferIN_OBJ.read();
    it += 1;
  }
}


void
buildResponseHead_OBJ(hls::stream<unsigned int> &dst,
		  unsigned short objID, unsigned short size,
		  unsigned char flags)
{
  int words32;

  words32 = (header_OBJ.cb<<16) | (header_OBJ.methodID<<8) | flags;
  dst.write(words32);
  if(flags & FLAG_HAS_PAYLOAD){
    words32 = (objID<<16) | size;
    dst.write(words32);
  }
}


void
buildResponse_OBJ(unsigned short objID, unsigned short size,
	      unsigned char flags)
{
  if (!bufferRESP_OBJ.empty()){
    buildResponseHead_OBJ(bufferOUT_OBJ, objID, size, flags);
    while (!bufferRESP_OBJ.empty())
      bufferOUT_OBJ.write(bufferRESP_OBJ.read());
  }
}


void
getRequestHead_OBJ()
{
  int words32[2];

  for(int it=0; it != 2; it++)
    words32[it] = bufferIN_OBJ.read();
  //byteHeader[it].words32 = bufferIN.read();

  header_OBJ.nodeID = (words32[0] >> 24) & 0xFF;
  header_OBJ.objectID = (words32[0] >> 16) & 0xFF;
  header_OBJ.methodID = (words32[0] >> 8) & 0xFF;
  header_OBJ.flags = words32[0] & 0xFF;
  header_OBJ.cb = (words32[1] >> 16) & 0xFFFF;
  header_OBJ.size = words32[1] & 0xFFFF;

  /*
  header.nodeID = byteHeader[0].words8[3];
  header.objectID = byteHeader[0].words8[2];
  header.methodID_flags = to_short(byteHeader[0].words8[1], byteHeader[0].words8[0]);
  header.cb = to_short(byteHeader[1].words8[3], byteHeader[1].words8[2]);
  header.size = to_short(byteHeader[1].words8[1], byteHeader[1].words8[0]);
  */
}


void
manager_OBJ(hls::stream<unsigned int> &timeClock)
{
#pragma HLS STREAM variable=bufferIN_OBJ depth=32
#pragma HLS STREAM variable=bufferOUT_OBJ depth=32
#pragma HLS STREAM variable=bufferRESP_OBJ depth=32
  getRequestHead_OBJ();

  if (ID_OBJ == header_OBJ.objectID || BROADCAST == header_OBJ.objectID){
    if (ID_OBJ_l2norm == header_OBJ.methodID){
      testing_OBJ_l2norm(bufferIN_OBJ, bufferRESP_OBJ);
      buildResponse_OBJ(ID_OBJ, sizeof(ret_OBJ_l2norm)/OBJ_BUS_WIDTH_BYTES,
     			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else{
      forward_OBJ(header_OBJ.size);
      buildResponseHead_OBJ(bufferOUT_OBJ, ID_OBJ, 0, 
			    FLAG_RESPONSE|FLAG_FAIL);
    } 
  }
  else if (ID_DOUBLE_SCALE2 == header_OBJ.objectID){
  //if (ID_DOUBLE_SCALE2 == header_OBJ.objectID || BROADCAST == header_OBJ.objectID){
    if (ID_DOUBLE_SCALE2_return == header_OBJ.methodID){
      running_DOUBLE_SCALE2_return(bufferIN_OBJ, scale2_return);
      buildResponseHead_OBJ(bufferOUT_OBJ, ID_DOUBLE_SCALE2, 0,
			    FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_DOUBLE_SCALE2_expect == header_OBJ.methodID){
      running_DOUBLE_SCALE2_expect(bufferIN_OBJ, scale2_expect);
      buildResponseHead_OBJ(bufferOUT_OBJ, ID_DOUBLE_SCALE2, 0,
			    FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_DOUBLE_SCALE2_callCount == header_OBJ.methodID){
      running_DOUBLE_SCALE2_callCount(bufferRESP_OBJ, scale2_callCount);
      buildResponse_OBJ(ID_DOUBLE_SCALE2, sizeof(ret_DOUBLE_SCALE2_callCount)/DOUBLE_SCALE2_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_DOUBLE_SCALE2_fails == header_OBJ.methodID){
      running_DOUBLE_SCALE2_fails(bufferRESP_OBJ, scale2_fails);
      buildResponse_OBJ(ID_DOUBLE_SCALE2, sizeof(ret_DOUBLE_SCALE2_fails)/DOUBLE_SCALE2_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_DOUBLE_SCALE2_failCount == header_OBJ.methodID){
      running_DOUBLE_SCALE2_failCount(bufferRESP_OBJ, scale2_failCount);
      buildResponse_OBJ(ID_DOUBLE_SCALE2, sizeof(ret_DOUBLE_SCALE2_failCount)/DOUBLE_SCALE2_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else if (ID_DOUBLE_SCALE2_callTime == header_OBJ.methodID){
      running_DOUBLE_SCALE2_callTime(bufferRESP_OBJ, scale2_callTime);
      buildResponse_OBJ(ID_DOUBLE_SCALE2, sizeof(ret_DOUBLE_SCALE2_callTime)/DOUBLE_SCALE2_BUS_WIDTH_BYTES,
			FLAG_HAS_PAYLOAD|FLAG_RESPONSE|FLAG_OK);
    }
    else{
      forward_OBJ(header_OBJ.size); 
      buildResponseHead_OBJ(bufferOUT_OBJ, ID_DOUBLE_SCALE2, 0,
			    FLAG_RESPONSE|FLAG_FAIL);
    }
  }
  else{
    forward_OBJ(header_OBJ.size);
    buildResponseHead_OBJ(bufferOUT_OBJ, NULL_OBJ, 0,
			  FLAG_RESPONSE|FLAG_FAIL);
  }
}


void
topTesting(hls::stream<unsigned int> din, hls::stream<unsigned int> dout,
	   hls::stream<unsigned int> timeClock)
{
  inputBuffer_OBJ(din);
  manager_OBJ(timeClock);
  outputBuffer_OBJ(dout);
}


