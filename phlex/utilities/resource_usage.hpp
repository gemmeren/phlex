#ifndef phlex_utilities_resource_usage_hpp
#define phlex_utilities_resource_usage_hpp

// =======================================================================================
// The resource_usage class tracks the CPU time and real time during the lifetime of a
// resource_usage object.  The destructor will also report the maximum RSS of the process.
// =======================================================================================

#include <chrono>

namespace phlex::experimental {
  class resource_usage {
  public:
    resource_usage() noexcept;
    ~resource_usage();

  private:
    std::chrono::time_point<std::chrono::steady_clock> begin_wall_;
    double begin_cpu_;
  };
}

#endif // phlex_utilities_resource_usage_hpp
