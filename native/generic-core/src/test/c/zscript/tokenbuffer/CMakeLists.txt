add_executable(ZsTokenBufferTests tokenbuffer_tests.c)

target_compile_options(ZsTokenBufferTests
    PRIVATE     ${test_compiler_options}
)

target_link_libraries(ZsTokenBufferTests
    PRIVATE
        zs_core_compiler_flags
        ZscriptCore
)

add_test(NAME StandardUse COMMAND ZsTokenBufferTests)
