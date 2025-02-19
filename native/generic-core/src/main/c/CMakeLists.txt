add_library(ZscriptCore INTERFACE)
target_include_directories(ZscriptCore INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
    $<INSTALL_INTERFACE:include>  # Installed headers go into include/zscript/
)
