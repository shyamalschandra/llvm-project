//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class X> class auto_ptr;

// auto_ptr(auto_ptr& a) throw();

#include <memory>
#include <cassert>

#include "../AB.h"

void
test()
{
    {
    B* p = new B(1);
    const std::auto_ptr<B> ap1(p);
    std::auto_ptr<A> ap2(ap1);
    assert(ap1.get() == 0);
    assert(ap2.get() == p);
    assert(A::count == 1);
    assert(B::count == 1);
    }
    assert(A::count == 0);
    assert(B::count == 0);
}

int main()
{
    test();
}
