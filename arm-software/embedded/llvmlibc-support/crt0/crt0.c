//
// Copyright (c) 2022-2025, Arm Limited and affiliates.
//
// Part of the Arm Toolchain project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "platform.h"

extern int main(int argc, char **argv);

extern void _platform_init();

extern char __data_source[];
extern char __data_start[];
extern char __data_size[];
extern char __bss_start[];
extern char __bss_size[];

void c_startup(void) {
  memcpy(__data_start, __data_source, (size_t)__data_size);
  memset(__bss_start, 0, (size_t)__bss_size);
  _platform_init();
  _Exit(main(0, NULL));
}

extern long __stack[];
__attribute__((naked)) void _start(void) {
  __asm__("mov sp, %0" : : "r"(__stack));
  __asm__("b c_startup");
}
