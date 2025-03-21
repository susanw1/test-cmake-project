cmake_minimum_required(VERSION 3.23)
project(generic-core
    VERSION     ${ZSCRIPT_CORE_VERSION}
    LANGUAGES   C
)

###### Compiler configuration
add_library(zs_core_compiler_flags INTERFACE)
target_compile_features(zs_core_compiler_flags
    INTERFACE   c_std_11
)

###### Compile and Testing
add_subdirectory(src/main/c)

include(CTest)
add_subdirectory(src/test/c)

###### Installation

# Install the target (header-only library) and headers
install(
    TARGETS     ZscriptCore
    EXPORT      t_zscript-generic-core-targets
    FILE_SET    HEADERS
    DESTINATION include
)

# Export targets and configuration file for downstream users
install(
    EXPORT      t_zscript-generic-core-targets
    FILE        t_zscript-generic-core-targets.cmake
    NAMESPACE   t_zscript::
    DESTINATION lib/cmake/t_zscript-generic-core
)

# Create the package configuration file
include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/src/main/cmake/t_zscript-generic-core-config.cmake.in
    ${CMAKE_BINARY_DIR}/t_zscript-generic-core-config.cmake
    INSTALL_DESTINATION lib/cmake/t_zscript-generic-core
)

install(
    FILES ${CMAKE_BINARY_DIR}/t_zscript-generic-core-config.cmake
    DESTINATION lib/cmake/t_zscript-generic-core
)

###### Packaging
# Packaging notes:
# * From generated generic-core/target/cmake (or wherever cmake generate put you), run `cpack --config CPackConfig.cmake`
# * Build creates TGZ and ZIP by default. Add DEB and/or RPM for others, eg:
#    set(CPACK_GENERATOR "TGZ;ZIP;DEB;RPM")
# * Ensure your platform has relevant tooling (eg sudo apt install rpm).

set(CPACK_GENERATOR "TGZ;ZIP")
set(CPACK_PACKAGE_NAME "t_zscript-generic-core")
set(CPACK_PACKAGE_VERSION "${ZSCRIPT_CORE_VERSION}")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")

# Debian-specific settings
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "${ZSCRIPT_CORE_MAINTAINER}")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "${ZSCRIPT_CORE_DESCRIPTION}")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.7)")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")

# RPM-specific settings
set(CPACK_RPM_PACKAGE_SUMMARY "${ZSCRIPT_CORE_DESCRIPTION}")
set(CPACK_RPM_PACKAGE_LICENSE "${ZSCRIPT_CORE_LICENSE}")
set(CPACK_RPM_PACKAGE_GROUP "Development/Libraries")

include(CPack)
