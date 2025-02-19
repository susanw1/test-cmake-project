add_executable(ZsTokenBufferTests tokenbuffer_tests.c)

target_link_libraries(ZsTokenBufferTests ZscriptCore)
add_test(NAME StandardUse COMMAND ZsTokenBufferTests)

target_compile_options(ZsTokenBufferTests PRIVATE ${test_compiler_options})
