############################################################
## Xilinx TSC 2018
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project proj
set_top dut
add_files dut.cpp
add_files -tb test_dut.cpp
open_solution "solution1"
set_part {xqku115-rlf1924-1-i} -tool vivado
create_clock -period 10 -name default
csim_design -clean -compiler clang
csynth_design
cosim_design -compiler clang -trace_level all
exit
