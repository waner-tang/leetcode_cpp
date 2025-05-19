cmake_minimum_required(VERSION 3.10)  # 规定cmake的最低版本要求
project(Cmake_test)  # 项目的名称

set(CMAKE_CXX_COMPILER "g++")  # 设置c++编译器


# 添加头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 自动搜索 src 目录中的所有源文件
file(GLOB SrcFiles 
    ${PROJECT_SOURCE_DIR}/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/hot100_fist_save/*.cpp
)

# 设置可执行文件输出路径为 build 目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# 创建可执行文件，名为 main，源文件为 SrcFiles
add_executable(main ${SrcFiles})
