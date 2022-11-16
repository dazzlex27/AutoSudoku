cmake_minimum_required (VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(THREADS_PREFER_PTHREAD_FLAG ON)

project ("AutoSudoku")

file(GLOB AutoSudoku_SRC "src/*.h" "src/*.cpp")
add_executable(AutoSudoku ${AutoSudoku_SRC})

target_link_libraries(AutoSudoku Threads::Threads) 