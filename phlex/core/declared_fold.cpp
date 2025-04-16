#include "phlex/core/declared_fold.hpp"

namespace phlex::experimental {
  declared_fold::declared_fold(algorithm_name name, std::vector<std::string> predicates) :
    products_consumer{std::move(name), std::move(predicates)}
  {
  }

  declared_fold::~declared_fold() = default;
}
