#!/bin/bash

# 定义源文件路径和目标目录路径
SOURCE_FILE="template/run.sh"
DEST_DIR="TO_DO"

# 检查源文件是否存在
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: Source file $SOURCE_FILE does not exist."
    exit 1
fi

# 检查目标目录是否存在
if [ ! -d "$DEST_DIR" ]; then
    echo "Error: Destination directory $DEST_DIR does not exist."
    exit 1
fi

# 遍历目标目录下的所有子文件夹
for subdir in "$DEST_DIR"/*/; do
    # 检查子文件夹是否存在
    if [ -d "$subdir" ]; then
        # 拷贝文件到子文件夹
        cp "$SOURCE_FILE" "$subdir"
		chmod +x "$subdir"run.sh
        if [ $? -eq 0 ]; then
            echo "File $SOURCE_FILE has been successfully copied to $subdir."
        else
            echo "Error: Failed to copy $SOURCE_FILE to $subdir."
        fi
    fi
done
