## topTesting directives
set_directive_interface -mode ap_ctrl_none "topTesting" 
set_directive_interface -mode ap_fifo "topTesting" din
set_directive_interface -mode ap_fifo "topTesting" dout
set_directive_dataflow "topTesting"
config_dataflow -default_channel fifo -fifo_depth 32
set_directive_inline "buildResponseHead_OBJ"


## Functions directives
## Directives of l2norm function
set_directive_inline -off "l2norm_mock"
set_directive_inline "testing_OBJ_l2norm_mock"
set_directive_inline "readParameters_OBJ_l2norm"
set_directive_inline "writeReturn_OBJ_l2norm"
