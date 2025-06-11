##!/bin/bash

# 定义要删除的文件和文件夹名称
declare -a files=("CMakeCache.txt" "cmake_install.cmake" "CMakeLists.txt" "compile_commands.json" "a.out" "Makefile")
declare -a dirs=("CMakeFiles" "bld")

# 删除指定的文件
echo "正在删除指定的文件..."
for file in "${files[@]}"; do
    find . -type f -name "$file" -exec rm -f {} \;
done

# 删除指定的文件夹
echo "正在删除指定的文件夹..."
for dir in "${dirs[@]}"; do
    find . -type d -name "$dir" -exec rm -rf {} \;
done

# 删除 run.sh 文件，但排除 template 路径下的 run.sh
echo "正在删除 run.sh 文件（排除 template 路径）..."
find . -type f -name "run.sh" ! -path "*/template/*" -exec rm -f {} \;

echo "清理完成。"
