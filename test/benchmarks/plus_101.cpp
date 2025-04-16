#include "phlex/module.hpp"

using namespace phlex::experimental;

namespace {
  int plus_101(int i) noexcept { return i + 101; }
}

PHLEX_EXPERIMENTAL_REGISTER_ALGORITHMS(m)
{
  m.with("plus_101", plus_101, concurrency::unlimited).transform("a").to("c");
}
