cmake_minimum_required(VERSION 2.8)

project(roi_selection)

find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

add_executable(roi_selection
    src/main.cpp
    src/box_selection.cpp
)

include_directories(roi_selection
    include/
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(roi_selection
    ${OpenCV_LIBRARIES}
    ${Boost_LIBRARIES}
)
