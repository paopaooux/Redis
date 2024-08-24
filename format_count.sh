#!/bin/bash

# 格式化
clang-format -i $(find src/include/ -type f -name *.h)
clang-format -i $(find src/main test/ -type f -name *.cpp)

# 统计代码行数
cloc --git $(git branch --show-current)
