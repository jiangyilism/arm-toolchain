/* Copyright (c) 2023-2025, Arm Limited and affiliates. 
 *
 * Part of the Arm Toolchain project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception */

#include <iostream>
#include <vector>

int main()
{
    std::vector vec {1, 2, 3, 4, 5};

    for (auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}