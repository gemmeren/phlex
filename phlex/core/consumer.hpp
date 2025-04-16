#ifndef phlex_core_consumer_hpp
#define phlex_core_consumer_hpp

#include "phlex/model/algorithm_name.hpp"

#include <string>
#include <vector>

namespace phlex::experimental {
  class consumer {
  public:
    consumer(algorithm_name name, std::vector<std::string> predicates);

    std::string full_name() const;
    std::string const& plugin() const noexcept;
    std::string const& algorithm() const noexcept;
    std::vector<std::string> const& when() const noexcept;

  private:
    algorithm_name name_;
    std::vector<std::string> predicates_;
  };
}

#endif // phlex_core_consumer_hpp
