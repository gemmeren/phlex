#include "phlex/module.hpp"

using namespace phlex::experimental;

namespace {
  int plus_one(int i) noexcept { return i + 1; }
}

PHLEX_EXPERIMENTAL_REGISTER_ALGORITHMS(m)
{
  m.with("plus_one", plus_one, concurrency::unlimited).transform("a").to("b");
}
