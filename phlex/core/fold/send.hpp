#ifndef phlex_core_fold_send_hpp
#define phlex_core_fold_send_hpp

// =======================================================================================
// Phlex requires fold results to be "sendable", where the result can be represented
// as a data product that is at least moveable.  For some types, notably std::atomic<T>
// specializations, move operations are not supported.  The framework thus permits a
// translation step where a non-moveable type can be converted to a type that is moveable.
//
// For non-moveable types, an overload of 'T send(U const&)' is required, where U is the
// unmoveable type, and T is the type that can be a represented as a data product.
// =======================================================================================

#include <atomic>
#include <concepts>

namespace phlex::experimental {
  template <typename T>
  T send(std::atomic<T> const& a)
  {
    return a.load();
  }
}

#endif // phlex_core_fold_send_hpp
