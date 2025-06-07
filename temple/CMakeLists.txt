# CMake 最低版本号要求

cmake_minimum_required (VERSION 4.0)

# 项目信息

project (leet)

#生成compile commands json
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# 指定生成目标

add_compile_options(-std=c++11 -Wall -g)


add_executable(a.out main.cpp)


# 添加自定义命令，将可执行文件移动到上一级目录
add_custom_command(TARGET a.out POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rename "${CMAKE_BINARY_DIR}/a.out" "${CMAKE_SOURCE_DIR}/../a.out"
    COMMENT "Moving executable to the parent directory"
    VERBATIM
)