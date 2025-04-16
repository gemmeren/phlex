#ifndef phlex_app_run_hpp
#define phlex_app_run_hpp

#include "boost/json.hpp"

#include <optional>

namespace phlex::experimental {
  void run(boost::json::object const& configurations,
           std::optional<std::string> dot_file,
           int max_parallelism);
}

#endif // phlex_app_run_hpp
