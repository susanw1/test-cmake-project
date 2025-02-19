cmake_minimum_required(VERSION 3.26)
project(generic-core)

### Compiler configuration
add_library(zs_core_compiler_flags INTERFACE)
target_compile_features(zs_core_compiler_flags INTERFACE c_std_11)

### Testing
include(CTest)

add_subdirectory(src/main/c)
add_subdirectory(src/test/c)
