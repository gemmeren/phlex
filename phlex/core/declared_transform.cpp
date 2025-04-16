#include "phlex/core/declared_transform.hpp"

namespace phlex::experimental {
  declared_transform::declared_transform(algorithm_name name, std::vector<std::string> predicates) :
    products_consumer{std::move(name), std::move(predicates)}
  {
  }

  declared_transform::~declared_transform() = default;
}
