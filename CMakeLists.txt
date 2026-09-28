cmake_minimum_required(VERSION 3.16)
project(cpp-ds-algo VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++17 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 创建静态库 ds
# ⚠️ 注意：这里只放明确分离了 .h 和 .cpp 的源文件（如链表、栈、队列、BST、堆）
# 如果是模板类（如 DynamicArray），千万不要写在这里！见问题二的说明。
add_library(ds INTERFACE)
target_include_directories(ds INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 公开头文件目录，链接此库的目标自动获得该路径
# 启用测试
enable_testing()
add_subdirectory(tests)