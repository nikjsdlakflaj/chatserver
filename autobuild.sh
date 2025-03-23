#!/bin/bash
set -ex

# 清理并创建 build 目录
rm -rf ./build/*
cd build

# 配置并编译（生成文件在 build 目录下）
cmake ..  # CMakeLists.txt 在上级目录
make

# 此时可执行文件默认在 build 目录中
ls -l ./  # 查看生成的文件
