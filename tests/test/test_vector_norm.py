#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-



import unittest
from rc_unittest_remote import RCUnittestTestCase

from vector_norm import l2norm
from scale2_mock import *


class TestL2Norm(RCUnittestTestCase):

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
            
        self.TEST_RESET()
        self.CONFIGURE_HW_ADDR(0x41000000)
        self.CONFIGURE_SKIP_INPUT(18)
        self.CONFIGURE_SKIP_OUTPUT(1)
        self.CONFIGURE_ENABLE_CYCLES(0)

        scale2_return(0.027164)
        scale2_expect(124.0)
  
        self.TEST_CONFIGURE()

        dout=[]
        l2norm(din, dout)
        
        self.assertTimeGT(220)
        self.assertTimeLT(500)

        for i in range(0,16):
            self.assertTrue(abs(ref[i]-dout[i]) < 0.0001)

        
        print ("scale2-CallCount {0}".format(scale2_callCount()))
        print ("scale2-FailureCount {0}".format(scale2_failureCount()))
        scale2_print_callTimes()
        scale2_print_failures()

        #self.assertTrue(0 == scale2_failureCount());

            
# if __name__ == '__main__':
#     unittest.main()
    
