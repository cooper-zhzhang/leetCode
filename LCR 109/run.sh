#!/bin/bash

g++ -g main.cpp

# 检查 a.out 文件是否存在
if [ -f "a.out" ]; then
    # 获取上一级目录路径
    parent_dir=$(dirname "$(pwd)")
    # 拷贝 a.out 到上一级目录
    cp a.out "$parent_dir"
else
    echo "编译失败"
fi


