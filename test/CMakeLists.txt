add_executable(test_main test_main.cpp)

target_link_libraries(test_main PRIVATE uavcalc)

add_test(NAME uavcalc_tests COMMAND test_main)