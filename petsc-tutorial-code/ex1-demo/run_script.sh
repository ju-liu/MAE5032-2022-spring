#!/bin/bash

#mpirun -np 1 ./ex1.out

#mpirun -np 1 ./ex1.out -snes_view

#mpirun -np 1 ./ex1.out -help

#mpirun -np 1 ./ex1.out -snes_monitor -snes_view

#mpirun -np 1 ./ex1.out -snes_type newtontr -snes_monitor -snes_view

mpirun -np 2 ./ex1.out -ksp_type richardson -pc_type asm \
  -pc_asm_blocks 4 -pc_asm_overlap 0 -pc_asm_local_type additive \
  -sub_pc_type lu \
  -snes_monitor_short -snes_converged_reason -snes_view \
  -log_view
