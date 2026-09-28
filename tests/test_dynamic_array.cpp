#include<ds/dynamic_array.hpp>


int main()
{
    DynamicArray<int> arr;
    for(int i=0;i<10;i++)
    {
        arr.ListInsert(i+1,i+1);
    }
    for(int i=0;i<10;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;

    DynamicArray<int> arr2 = arr; //测试拷贝构造函数
    for(int i=0;i<10;i++)
    {
        std::cout<<arr2[i]<<" ";
    }
    std::cout<<std::endl;

    DynamicArray<int> arr3;
    arr3 = arr; //测试拷贝赋值运算符
    for(int i=0;i<10;i++)
    {
        std::cout<<arr3[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}