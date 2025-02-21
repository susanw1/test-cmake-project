add_executable(ZsZscriptSysTests zscriptsys_tests.c)

target_compile_options(ZsZscriptSysTests
    PRIVATE     ${test_compiler_options}
)

target_link_libraries(ZsZscriptSysTests
    PRIVATE     zs_core_compiler_flags
                ZscriptCore
)

add_test(NAME SystemTest COMMAND ZsZscriptSysTests)
