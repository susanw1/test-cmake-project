add_executable(ZsZscriptMod000x module-000x_tests.c)

target_compile_options(ZsZscriptMod000x
    PRIVATE ${test_compiler_options}
)
target_link_libraries(ZsZscriptMod000x
    PRIVATE
        ZscriptRuntime
        zs_compiler_flags
)

add_test(NAME Module-000x COMMAND ZsZscriptMod000x)
