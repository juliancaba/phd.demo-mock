#ifndef TYPEDOUBLESFUNC_H
#define TYPEDOUBLESFUNC_H

struct struct_SCALE2_PARAM
{
  float sum;
};
typedef struct_SCALE2_PARAM tSCALE2_PARAM;

struct struct_SCALE2_RETURN
{
  float _return;
};
typedef struct_SCALE2_RETURN tSCALE2_RETURN;

struct struct_SCALE2_FAIL
{
  unsigned int _callCount;
  unsigned int _time;
  tSCALE2_PARAM _param;
  tSCALE2_PARAM _expect;
};
typedef struct_SCALE2_FAIL tSCALE2_FAIL;

#endif
