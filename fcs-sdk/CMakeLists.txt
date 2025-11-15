cmake_minimum_required(VERSION 3.10)
project(FCS-SDK)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к include
include_directories(${CMAKE_SOURCE_DIR}/include)

# Список исходников
set(FCS_SRC
    src/fcs.cpp
    src/f_operator.cpp
    src/e_operator.cpp
    src/finv_operator.cpp
    src/g_operator.cpp
)

# Основная библиотека
add_library(fcs-sdk STATIC ${FCS_SRC})

# Примеры
add_executable(simple_loop_test examples/simple_loop_test.cpp)
target_link_libraries(simple_loop_test fcs-sdk)

add_executable(servo_position_control examples/servo_position_control.cpp)
target_link_libraries(servo_position_control fcs-sdk)

add_executable(drone_altitude_control examples/drone_altitude_control.cpp)
target_link_libraries(drone_altitude_control fcs-sdk)
