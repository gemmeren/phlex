add_unit_test(sized_tuple LIBRARIES phlex::utilities)

add_catch_test(sleep_for LIBRARIES phlex::utilities)
add_catch_test(thread_counter LIBRARIES phlex::utilities TBB::tbb)
