configure_file(version.cpp.in version.cpp @ONLY)

add_library(run_phlex SHARED load_module.cpp run.cpp version.cpp)
target_link_libraries(run_phlex PRIVATE Boost::json phlex::core)

# We'll use C++17's filesystem instead of Boost's
target_compile_definitions(run_phlex PRIVATE BOOST_DLL_USE_STD_FS)

add_executable(phlex phlex.cpp)
target_link_libraries(
  phlex PRIVATE Boost::json Boost::program_options run_phlex phlex::core
                jsonnet::lib
  )

install(TARGETS run_phlex phlex)
