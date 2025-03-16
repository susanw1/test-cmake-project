add_library(ZscriptRuntime INTERFACE)

target_include_directories(ZscriptRuntime INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_PREFIX_PATH}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(ZscriptRuntime INTERFACE
    FILE_SET    HEADERS
    BASE_DIRS   ${CMAKE_CURRENT_SOURCE_DIR}
    FILES       t_zscript-modules
)
