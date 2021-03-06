//===-- LanaiTargetInfo.cpp - Lanai Target Implementation -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

namespace llvm {
Target &getTheLanaiTarget() {
  static Target TheLanaiTarget;
  return TheLanaiTarget;
}
} // namespace llvm

extern "C" void LLVMInitializeLanaiTargetInfo() {
  RegisterTarget<Triple::lanai> X(getTheLanaiTarget(), "lanai", "Lanai",
                                  "Lanai");
}
