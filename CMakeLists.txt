cmake_minimum_required(VERSION 3.10)

project(beast_test)

add_executable(beast_test main.cpp)
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED)

target_link_libraries(
    beast_test 
        PUBLIC 
    Boost::boost
    Threads::Threads
    OpenMP::OpenMP_CXX
)
target_compile_options(beast_test PUBLIC "-fopenmp")
