#include "phlex/core/declared_predicate.hpp"

namespace phlex::experimental {
  declared_predicate::declared_predicate(algorithm_name name, std::vector<std::string> predicates) :
    products_consumer{std::move(name), std::move(predicates)}
  {
  }

  declared_predicate::~declared_predicate() = default;
}
