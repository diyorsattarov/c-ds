add_library(node
    node/node.cpp
    ../include/node/node.h
)

target_include_directories(node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})