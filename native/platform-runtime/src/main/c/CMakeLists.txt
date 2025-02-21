add_library(ZscriptRuntime INTERFACE)

target_include_directories(ZscriptRuntime INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
#    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>  # Add the binary dir to the INTERFACE include path
    $<INSTALL_INTERFACE:include>
)

target_sources(ZscriptRuntime INTERFACE
    FILE_SET    HEADERS
    BASE_DIRS   ${CMAKE_CURRENT_SOURCE_DIR}
    FILES       zscript-modules
)

#install(FILES ${CMAKE_CURRENT_BINARY_DIR}/zscript/sys/core-version.h
#    DESTINATION include/zscript/sys
#)
