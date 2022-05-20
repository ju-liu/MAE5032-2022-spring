#!/bin/bash

#mpirun -np 2 ./ex5.out -mat_view -ksp_view

#mpirun -np 2 ./ex5.out -ksp_type cg -pc_type none  -ksp_monitor  -ksp_view

mpirun -np 3 ./ex5.out -ksp_type gmres \
  -ksp_gmres_restart 30 -ksp_rtol 1.0e-10 \
  -ksp_atol 1.0e-50 -ksp_max_it 1500 \
  -ksp_gmres_modifiedgramschmidt \
  -pc_type asm \
  -sub_ksp_type richardson \
  -sub_pc_type icc -ksp_monitor_short \
  -ksp_converged_reason \
  -ksp_view
