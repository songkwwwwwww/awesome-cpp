cmake_minimum_required(VERSION 3.16)

# Set up language settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(PROJECT_NAME tutorial_1)

# Find Halide
find_package(Halide REQUIRED)

# Main executable
add_executable($(PROJECT_NAME) main.cpp)
target_link_libraries($(PROJECT_NAME)
                      PRIVATE
		      Halide::ImageIO
                      )
