cmake_minimum_required(VERSION 3.23)
project(generic-core VERSION ${ZSCRIPT_CORE_VERSION})

#######
###### Compiler configuration
#######
add_library(zs_core_compiler_flags INTERFACE)
target_compile_features(zs_core_compiler_flags INTERFACE c_std_11)


#######
###### Compile and Testing
#######
add_subdirectory(src/main/c)

include(CTest)
add_subdirectory(src/test/c)

#######
###### Installation
#######

# Install the target (header-only library) and headers
install(
    TARGETS ZscriptCore
    EXPORT zscript-generic-coreTargets
    FILE_SET HEADERS DESTINATION include
)

# Export targets and configuration file for downstream users
install(
    EXPORT zscript-generic-coreTargets
    FILE zscript-generic-coreTargets.cmake
    NAMESPACE zscript::
    DESTINATION lib/cmake/zscript-generic-core
)

# Create the package configuration file
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/zscript-generic-coreConfig.cmake.in
    ${CMAKE_BINARY_DIR}/zscript-generic-coreConfig.cmake
    INSTALL_DESTINATION lib/cmake/zscript-generic-core
)

set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_NAME "zscript-generic-core")
set(CPACK_PACKAGE_VERSION "${ZSCRIPT_CORE_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
include(CPack)
