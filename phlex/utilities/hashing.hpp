#ifndef phlex_utilities_hashing_hpp
#define phlex_utilities_hashing_hpp

#include <cstdint>
#include <string>

namespace phlex::experimental {
  std::size_t hash(std::string const& str);
  std::size_t hash(std::size_t i) noexcept;
  std::size_t hash(std::size_t i, std::size_t j);
  std::size_t hash(std::size_t i, std::string const& str);
  template <typename... Ts>
  std::size_t hash(std::size_t i, std::size_t j, Ts... ks)
  {
    return hash(hash(i, j), ks...);
  }
}

#endif // phlex_utilities_hashing_hpp
