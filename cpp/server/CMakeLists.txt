
set(SRC_LIST 
"${CMAKE_CURRENT_SOURCE_DIR}/HelloI.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp"
)

set_source_files_properties("${SLICE_GEN_CPP}" PROPERTIES GENERATED ON)

add_executable(server ${SRC_LIST} ${SLICE_GEN_CPP})
target_link_libraries(server Ice IceUtil)
