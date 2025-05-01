add_library(phlex_metaprogramming SHARED function_name.cpp)
target_include_directories(
  phlex_metaprogramming PRIVATE ${PROJECT_SOURCE_DIR} ${BACKTRACE_INC}
  )
target_link_libraries(
  phlex_metaprogramming
  PRIVATE Boost::stacktrace_basic ${BACKTRACE_LIB}
  PUBLIC Boost::headers
  )
target_compile_definitions(
  phlex_metaprogramming PRIVATE BOOST_STACKTRACE_USE_BACKTRACE
                                BOOST_STACKTRACE_GNU_SOURCE_NOT_REQUIRED
  )

# Interface library
add_library(phlex_metaprogramming_int INTERFACE)
target_include_directories(
  phlex_metaprogramming_int INTERFACE "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
                                      "$<INSTALL_INTERFACE:include>"
  )

target_link_libraries(phlex_metaprogramming_int INTERFACE phlex_metaprogramming)

add_library(phlex::metaprogramming ALIAS phlex_metaprogramming_int)

install(TARGETS phlex_metaprogramming)
