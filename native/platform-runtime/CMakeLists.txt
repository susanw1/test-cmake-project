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
    find_package(t_zscript-generic-core REQUIRED)
else()
    # If not using installed version, point to source dir
    add_subdirectory(../generic-core generic-core)
endif()


# Create main target for this Project
add_library(ZscriptPlatformRuntime INTERFACE)

target_link_libraries(ZscriptPlatformRuntime
    INTERFACE
        zscript::ZscriptCore
        ZscriptRuntime
)

###### Compile and Testing
add_subdirectory(src/main/c)

include(CTest)
add_subdirectory(src/test/c)

###### Installation

# Install the target (header-only library) and headers
install(
    TARGETS     ZscriptRuntime
    EXPORT      t_zscript-platform-runtime-targets
    FILE_SET    HEADERS
    DESTINATION include
)

# Export targets and configuration file for downstream users
install(
    EXPORT      t_zscript-platform-runtime-targets
    FILE        t_zscript-platform-runtime-targets.cmake
    NAMESPACE   t_zscript-platform-runtime::
    DESTINATION lib/cmake/t_zscript-platform-runtime
)

###### Packaging

# Create the package configuration file
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/src/main/cmake/t_zscript-platform-runtime-config.cmake.in
    ${CMAKE_BINARY_DIR}/t_zscript-platform-runtime-config.cmake
    INSTALL_DESTINATION lib/cmake/t_zscript-platform-runtime
)

install(
    FILES ${CMAKE_BINARY_DIR}/t_zscript-platform-runtime-config.cmake
    DESTINATION lib/cmake/t_zscript-platform-runtime
)
