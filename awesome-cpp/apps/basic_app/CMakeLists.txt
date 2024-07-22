set( TARGET_NAME program )

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

add_executable(${TARGET_NAME} ${SRC_FILES})
target_link_libraries(${TARGET_NAME} PUBLIC sum_lib)
