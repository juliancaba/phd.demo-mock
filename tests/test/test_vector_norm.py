#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-



import unittest
from unittest_time import TimeTestCase

from vector_norm import l2norm
from scale2_mock import *


class TestL2Norm(TimeTestCase):

    def test_l2norm(self):
        ref = [0.0, 0.027164, 0.054328,
               0.081492, 0.108655, 0.135819,
               0.162983, 0.190147, 0.217311,
               0.244475, 0.271639, 0.298802,
               0.325966, 0.353130, 0.380294,
               0.407458];
        din = []
        for i in range(0,16):
            din.append(float(i))
            
        self.UNITTEST_TIME_RESET()
        self.CONFIGURE_UNITTEST_TIME_HW_ADDR(0x41000000)
        self.CONFIGURE_UNITTEST_TIME_INPUT_32BIT_WORDS(18)
        self.CONFIGURE_UNITTEST_TIME_OUTPUT_32BIT_WORDS(1)
        self.CONFIGURE_UNITTEST_TIME_ENABLE_CYCLES(0)

        scale2_return(0.1)
        scale2_expect(1240.0)
  
        self.UNITTEST_TIME_CONFIGURE()

        dout=[]
        l2norm(din, dout)
        
        self.assertTimeGT(220)
        self.assertTimeGT(500)

        for i in range(0,16):
            self.assertEqual(ref[i], dout[i])

        
        print ("scale2-CallCount {0}\n").format(scale2_callCount())
        print ("scale2-FailureCount {0}\n").format(scale2_failureCount())
        scale2_print_callTimes()
        scale2_print_failures()

            
# if __name__ == '__main__':
#     unittest.main()
    
