#ifndef phlex_core_detail_port_names_hpp
#define phlex_core_detail_port_names_hpp

#include "phlex/core/input_arguments.hpp"
#include "phlex/core/specified_label.hpp"

#include <array>
#include <cstdint>
#include <tuple>
#include <utility>

namespace phlex::experimental::detail {
  template <typename InputArgs>
  auto port_names(InputArgs const& args)
  {
    constexpr auto N = std::tuple_size_v<InputArgs>;
    auto unpack = []<std::size_t... Is>(InputArgs const& inputs, std::index_sequence<Is...>) {
      return std::array{std::get<Is>(inputs).label...};
    };
    return unpack(args, std::make_index_sequence<N>{});
  }
}

#endif // phlex_core_detail_port_names_hpp
