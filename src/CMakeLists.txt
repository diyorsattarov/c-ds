add_library(node
    node/node.cpp
    ../include/node/node.h
)

target_include_directories(node PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(linkedlist
    linkedlist/linkedlist.cpp
    ../include/linkedlist/linkedlist.h
)

target_include_directories(linkedlist PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})