############################################################
## Xilinx TSC 2018
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project proj
set_top dut
add_files dut.cpp
add_files -tb test_dut.cpp
open_solution "solution1"
set_part {xqku115-rlf1924-2-i}
create_clock -period 10 -name default
csim_design -clean -compiler gcc
csynth_design
cosim_design -compiler gcc -trace_level all
exit