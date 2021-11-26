/*
 * Copyright 2021, Oak Ridge National Laboratory.
 * MGARD-X: MultiGrid Adaptive Reduction of Data Portable across GPUs and CPUs
 * Author: Jieyang Chen (chenj3@ornl.gov)
 * Date: December 1, 2021
 */


#include "cuda/DataRefactoring.hpp"

#include <iostream>

#include <chrono>
namespace mgard_x {

template void recompose<1, float, CUDA>(Handle<1, float> & handle,
                                      SubArray<1, float, CUDA>& v,
                                      SIZE l_target, int queue_idx);
} // namespace mgard_x