# CMake 最低版本号要求

cmake_minimum_required (VERSION 2.8)

# 项目信息

project (leet)

#生成compile commands json
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# 指定生成目标

add_compile_options(-std=c++11 -Wall -Werror -g)


add_executable(a.out main.cpp)

# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1

#set(BUTIL_SOURCES
  #     ${PROJECT_SOURCE_DIR}/src/butil/third_party/dmg_fp/g_fmt.cc
