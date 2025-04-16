#ifndef phlex_core_node_catalog_hpp
#define phlex_core_node_catalog_hpp

#include "phlex/core/declared_fold.hpp"
#include "phlex/core/declared_observer.hpp"
#include "phlex/core/declared_output.hpp"
#include "phlex/core/declared_predicate.hpp"
#include "phlex/core/declared_transform.hpp"
#include "phlex/core/declared_unfold.hpp"
#include "phlex/core/registrar.hpp"

namespace phlex::experimental {
  struct node_catalog {
    auto register_predicate(std::vector<std::string>& errors)
    {
      return registrar{predicates_, errors};
    }
    auto register_observer(std::vector<std::string>& errors)
    {
      return registrar{observers_, errors};
    }
    auto register_output(std::vector<std::string>& errors) { return registrar{outputs_, errors}; }
    auto register_fold(std::vector<std::string>& errors) { return registrar{folds_, errors}; }
    auto register_unfold(std::vector<std::string>& errors) { return registrar{unfolds_, errors}; }
    auto register_transform(std::vector<std::string>& errors)
    {
      return registrar{transforms_, errors};
    }

    declared_predicates predicates_{};
    declared_observers observers_{};
    declared_outputs outputs_{};
    declared_folds folds_{};
    declared_unfolds unfolds_{};
    declared_transforms transforms_{};
  };
}

#endif // phlex_core_node_catalog_hpp
