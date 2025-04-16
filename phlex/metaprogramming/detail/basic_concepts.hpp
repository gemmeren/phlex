#ifndef phlex_metaprogramming_detail_basic_concepts_hpp
#define phlex_metaprogramming_detail_basic_concepts_hpp

namespace phlex::experimental::detail {
  template <typename T>
  concept has_call_operator = requires { &T::operator(); };
}

#endif // phlex_metaprogramming_detail_basic_concepts_hpp
