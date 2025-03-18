set(link_libs
        zs_core_compiler_flags
        ZscriptCore
)

# Fix the libs above, so we don't have to supply them in every test
macro(invoke_test test_name)
    invoke_test_with_libs("${test_name}" "${link_libs}")
endmacro()

invoke_test(zscriptsys1)
invoke_test(zscriptsys2)
