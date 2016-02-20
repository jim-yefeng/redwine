
set(SRC_LIST 
"${CMAKE_CURRENT_SOURCE_DIR}/Client.cpp"
)

set_source_files_properties("${SLICE_GEN_CPP}" PROPERTIES GENERATED ON)

add_executable(client ${SRC_LIST} ${SLICE_GEN_CPP})
target_link_libraries(client Ice IceUtil)
