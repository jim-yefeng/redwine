set(SLICE_GEN "${CMAKE_CURRENT_SOURCE_DIR}/gen")

file(MAKE_DIRECTORY "${SLICE_GEN}")

add_custom_command(OUTPUT "${SLICE_GEN}/Hello.cpp" "${SLICE_GEN}/Hello.h"
                   COMMAND /usr/bin/slice2cpp "${SLICE_DIR}/Hello.ice"
                   DEPENDS "${SLICE_DIR}/Hello.ice"
                   WORKING_DIRECTORY "${SLICE_GEN}")
add_custom_target(HelloTarget ALL
                  DEPENDS "${SLICE_GEN}/Hello.cpp" "${SLICE_GEN}/Hello.h")
                   
                  