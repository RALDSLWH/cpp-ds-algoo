# 定义测试文件名列表
set(TEST_NAMES
    dynamic_array
    #singly_linked_list
    #doubly_linked_list
    #stack
    #queue
    #bst
    #heap
    #hash_table
)

# 循环生成每个测试可执行文件
foreach(name ${TEST_NAMES})
    add_executable(test_${name} test_${name}.cpp)
    target_link_libraries(test_${name} PRIVATE ds)
    add_test(NAME test_${name} COMMAND test_${name})
endforeach()