#!/bin/bash

# A bash script to build the llvmlibc overlay for the Arm Toolchain for Embedded

# The script creates a build of the toolchain in the 'build_llvmlibc_overlay'
# directory, inside the repository tree.

set -ex

export CC=clang
export CXX=clang++

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
REPO_ROOT=$( git -C ${SCRIPT_DIR} rev-parse --show-toplevel )
BUILD_DIR=${REPO_ROOT}/build_llvmlibc_overlay

mkdir -p ${BUILD_DIR}
cd ${BUILD_DIR}

cmake ../arm-software/embedded -GNinja -DFETCHCONTENT_QUIET=OFF -DLLVM_TOOLCHAIN_C_LIBRARY=llvmlibc -DLLVM_TOOLCHAIN_LIBRARY_OVERLAY_INSTALL=on
ninja package-llvm-toolchain

# The package-llvm-toolchain target will produce a .tar.xz package, but we also
# a zip version for Windows users
cpack -G ZIP
