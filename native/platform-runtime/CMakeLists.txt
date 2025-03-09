cmake_minimum_required(VERSION 3.23)
project(platform-runtime
    VERSION     1.0
)

###### Compiler configuration
add_library(zs_compiler_flags INTERFACE)
target_compile_features(zs_compiler_flags
    INTERFACE   c_std_11
)


option(USE_INSTALLED_ZSCRIPT "Use installed zscript-generic-core instead of source" ON)

if (USE_INSTALLED_ZSCRIPT)
    find_package(zscript-generic-core REQUIRED)
else()
    # If not using installed version, point to source dir
    add_subdirectory(../generic-core generic-core)
endif()


add_library(ZscriptPlatformRuntime INTERFACE)

target_link_libraries(ZscriptPlatformRuntime
    INTERFACE zscript::ZscriptCore
)

target_link_libraries(ZscriptPlatformRuntime INTERFACE ZscriptRuntime) # debugging



###### Compile and Testing
add_subdirectory(src/main/c)

include(CTest)
add_subdirectory(src/test/c)

###### Installation

# Install the target (header-only library) and headers
install(
    TARGETS     ZscriptRuntime
    EXPORT      zscript-platform-runtimeTargets
    FILE_SET    HEADERS
    DESTINATION include
)

# Export targets and configuration file for downstream users
install(
    EXPORT      zscript-platform-runtimeTargets
    FILE        zscript-platform-runtimeTargets.cmake
    NAMESPACE   zscript-platform-runtime::
    DESTINATION lib/cmake/zscript-platform-runtime
)

###### Packaging

# Create the package configuration file
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/src/main/cmake/zscript-platform-runtimeConfig.cmake.in
    ${CMAKE_BINARY_DIR}/zscript-platform-runtimeConfig.cmake
    INSTALL_DESTINATION lib/cmake/zscript-platform-runtime
)

install(
    FILES ${CMAKE_BINARY_DIR}/zscript-platform-runtimeConfig.cmake
    DESTINATION lib/cmake/zscript-platform-runtime
)
