add_library(ZscriptCore INTERFACE)

target_include_directories(ZscriptCore INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_sources(ZscriptCore INTERFACE
    FILE_SET HEADERS BASE_DIRS zscript
)
