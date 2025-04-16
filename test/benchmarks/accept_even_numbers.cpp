#include "phlex/module.hpp"

#include <string>

PHLEX_EXPERIMENTAL_REGISTER_ALGORITHMS(m, config)
{
  m.with(
     "accept_even_numbers",
     [](int i) { return i % 2 == 0; },
     phlex::experimental::concurrency::unlimited)
    .evaluate(config.get<std::string>("consumes"));
}
