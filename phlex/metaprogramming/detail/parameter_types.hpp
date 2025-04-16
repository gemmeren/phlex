#ifndef phlex_metaprogramming_detail_parameter_types_hpp
#define phlex_metaprogramming_detail_parameter_types_hpp

#include "phlex/metaprogramming/detail/basic_concepts.hpp"

#include <tuple>

namespace phlex::experimental::detail {
  template <typename T, typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (T::*)(Args...));

  template <typename T, typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (T::*)(Args...) const);

  template <typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (*)(Args...));

  // noexcept overloads
  template <typename T, typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (T::*)(Args...) noexcept);

  template <typename T, typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (T::*)(Args...) const noexcept);

  template <typename R, typename... Args>
  std::tuple<Args...> parameter_types_impl(R (*)(Args...) noexcept);

  template <has_call_operator T>
  auto parameter_types_impl(T&&) -> decltype(parameter_types_impl(&T::operator()));
}

#endif // phlex_metaprogramming_detail_parameter_types_hpp
