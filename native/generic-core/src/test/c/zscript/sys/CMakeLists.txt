set(link_libs
        zs_core_compiler_flags
        ZscriptCore
)

macro(invoke_test test_name)
    add_executable(${test_name} ${test_name}_tests.c)
    target_compile_options(${test_name}
        PRIVATE     ${test_compiler_options}
    )
    target_link_libraries(${test_name} PRIVATE ${link_libs})
    add_test(NAME ${test_name} COMMAND ${test_name})
endmacro()

invoke_test(zscriptsys1)
invoke_test(zscriptsys2)
