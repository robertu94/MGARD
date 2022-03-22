/*
 * Copyright 2022, Oak Ridge National Laboratory.
 * MGARD-X: MultiGrid Adaptive Reduction of Data Portable across GPUs and CPUs
 * Author: Jieyang Chen (chenj3@ornl.gov)
 * Date: March 17, 2022
 */

#include "mgard-x/DataRefactoring/MultiDimension/DataRefactoring.hpp"
#include "mgard-x/DataRefactoring/SingleDimension/DataRefactoring.hpp"

#include <iostream>

#include <chrono>
namespace mgard_x {

template void decompose<4, float, SYCL>(Hierarchy<4, float, SYCL> &hierarchy,
                                       SubArray<4, float, SYCL> &v,
                                       SIZE l_target, int queue_idx);
template void
    decompose_single<4, float, SYCL>(Hierarchy<4, float, SYCL> &hierarchy,
                                    SubArray<4, float, SYCL> &v, SIZE l_target,
                                    int queue_idx);
} // namespace mgard_x