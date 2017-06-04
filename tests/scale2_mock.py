#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
from hwt_proxy import FPGA_hwtClient
from arm_casting_ieee754 import *


_hw_addr = 0x42000000

_scale2_failurecount = 0
_scale2_failurecount_vld = 0

_scale2_callcount = 0
_scale2_callcount_vld = 0


def scale2_return(a):      
    din = []
    din.extend(int_to_byte(0x00020104))
    din.extend(int_to_byte(0x00000001))
    din.extend(int_to_byte(float_to_ieee754(a)))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]

    del testCli
    del idout

    
def scale2_expect(a):      
    din = []
    din.extend(int_to_byte(0x00020204))
    din.extend(int_to_byte(0x00000001))
    din.extend(int_to_byte(float_to_ieee754(a)))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]

    del testCli
    del idout

    
def scale2_callCount():      
    din = []
    din.extend(int_to_byte(0x00020300))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]
    _scale2_callcount = idout[2]
    _scale2_callcount_vld = 1
    
    del testCli
    del idout
    return _scale2_callcount


def scale2_failureCount():      
    din = []
    din.extend(int_to_byte(0x00020400))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]
    _scale2_failurecount = idout[2]
    _scale2_failurecount_vld = 1
    
    del testCli
    del idout
    return _scale2_failurecount



def scale2_callTime():      
    din = []
    din.extend(int_to_byte(0x00020500))
    din.extend(int_to_byte(0x00000000))

    testCli = FPGA_hwtClient()
    testCli.arguments(_hw_addr, din)
    testCli.main([None])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    head1 = idout[0]
    head2 = idout[1]
    _time = idout[2]
        
    del testCli
    del idout
    return _time


def scale2_print_callTimes():
    if _scale2_callcount_vld:
        calls = _scale2_callcount;
    else:
        calls = scale2_callCount();

    if callss == 0:
        print("{0}: No calls\n").format(__name__)
    else:
        for it in (0,calls):
            din = []
            din.extend(int_to_byte(0x00020500))
            din.extend(int_to_byte(0x00000000))

            testCli = FPGA_hwtClient()
            testCli.arguments(_hw_addr, din)
            testCli.main([None])
            dout = testCli.result()
            idout = charSeq_to_intSeq(dout)

            head1 = idout[0]
            head2 = idout[1]
            _time = idout[2]
            print ("\tTime {0}\n").format(_time)

            del testCli
            del idout



  
def scale2_print_failures():
    if _scale2_failurecount_vld:
        failures = _scale2_failurecount;
    else:
        failures = scale2_failureCount();

    if failures == 0:
        print("{0}: No failures\n").format(__name__)
    else:
        for it in (0,failures):
            din = []
            din.extend(int_to_byte(0x00020600))
            din.extend(int_to_byte(0x00000000))

            testCli = FPGA_hwtClient()
            testCli.arguments(_hw_addr, din)
            testCli.main([None])
            dout = testCli.result()
            idout = charSeq_to_intSeq(dout)

            head1 = idout[0]
            head2 = idout[1]
            callCount = idout[2]
            print ("\tcallCount {0}\n").format(callCount)
            time = idout[3]
            print ("\tTime {0}\n").format(time)
            expected = ieee754_to_float(idout[4])
            print ("\tExpected {0}\n").format(expected)
            actual = ieee754_to_float(idout[5])
            print ("\tActual {0}\n").format(actual)

            del testCli
            del idout


