# include(FetchContent)
# FetchContent_Declare(
# googletest
# GIT_REPOSITORY https://github.com/google/googletest.git
# GIT_TAG release-1.12.1

# # URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# FetchContent_MakeAvailable(googletest)

SET(TEST_NAME awesome-cmake-test)

file(GLOB_RECURSE TEST_SRC_FILES CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
add_executable(${TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${TEST_NAME} PRIVATE sum_lib gtest gmock gtest_main)
