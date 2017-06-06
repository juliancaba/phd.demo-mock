#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
from hwt_proxy import sendMessage
from arm_casting_ieee754 import *


_hw_addr = 0x42000000

_scale2_failurecount = 0
_scale2_failurecount_vld = 0

_scale2_callcount = 0
_scale2_callcount_vld = 0


def scale2_return(a):
    din = []
    din.extend(int_to_byte(float_to_ieee754(a)))
    head,payload = sendMessage(_hw_addr, 0x00020104, 0x00000001, din)
    
    
def scale2_expect(a):
    din = []
    din.extend(int_to_byte(float_to_ieee754(a)))
    head,payload = sendMessage(_hw_addr, 0x00020204, 0x00000001, din)

    
def scale2_callCount():
    head,payload = sendMessage(_hw_addr, 0x00020300, 0x00000000, None)  
    _scale2_callcount = payload[0]
    _scale2_callcount_vld = 1
    return _scale2_callcount


def scale2_failureCount():
    head,payload = sendMessage(_hw_addr, 0x00020400, 0x00000000, None)  
    _scale2_failurecount = payload[0]
    _scale2_failurecount_vld = 1
    return _scale2_failurecount


def scale2_callTime():
    head,payload = sendMessage(_hw_addr, 0x00020500, 0x00000000, None)  
    _time = payload[0]
    return _time


def scale2_print_callTimes():
    if _scale2_callcount_vld:
        calls = int(_scale2_callcount,16);
    else:
        calls = int(scale2_callCount(),16);

    if calls == 0:
        print("{0}: No calls".format(sys._getframe().f_code.co_name))
    else:
        print("Calls - {0}".format(sys._getframe().f_code.co_name))
        for it in range(0,calls):
            _time = int(scale2_callTime(),16)
            print ("\tTime {0}".format(_time))

  
def scale2_print_failures():
    if _scale2_failurecount_vld:
        failures = int(_scale2_failurecount,16);
    else:
        failures = int(scale2_failureCount(),16);

    if failures == 0:
        print("{0}: No failures".format(sys._getframe().f_code.co_name))
    else:
        print("Failures - {0}".format(sys._getframe().f_code.co_name))
        for it in range(0,failures):
            head,payload = sendMessage(_hw_addr, 0x00020600, 0x00000000, None)  
            callCount = int(payload[0],16)
            print ("\tcallCount {0}".format(callCount))
            time = int(payload[1],16)
            print ("\tTime {0}".format(time))
            expected = ieee754_to_float(payload[2])
            print ("\tExpected {0}".format(expected))
            actual = ieee754_to_float(payload[3])
            print ("\tActual {0}".format(actual))

