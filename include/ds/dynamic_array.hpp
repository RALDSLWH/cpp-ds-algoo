#pragma once //防止头文件被多次包含
#include<iostream>
#include <stdexcept> //引入标准异常处理库
#define InitSize 100

template <typename T>
struct DynamicArray{
    T* data;//指向动态数组的指针
    int length;//动态数组的当前长度
    int MaxSize;//动态数组的最大容量

    //构造和析构
    DynamicArray()
    {
        length = 0;
        MaxSize = InitSize;
        data = new T[MaxSize];
    }

    //拷贝构造函数（深拷贝）
    DynamicArray(const DynamicArray& other)
    {
      length =other.length;
      MaxSize =other.MaxSize;
      data =new T[MaxSize];//为新对象分配内存
      for(int i=0;i<other.length;i++)  //注意是other.length而不是MaxSize  若MaxSize大于length，则会访问未初始化的内存，导致未定义行为
      {
        data[i]=other.data[i];
      }//将other对象的数据复制到新对象中
    }

    //拷贝赋值运算符（深拷贝）
    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other) //防止自我赋值
        {
            delete[] data; //释放原有内存
            length = other.length;
            MaxSize = other.MaxSize;
            data = new T[MaxSize]; //为新对象分配内存
            for (int i = 0; i < length; i++)
            {
                data[i] = other.data[i]; //将other对象的数据复制到新对象中
            }
        }
        return *this;
    }

    //扩容操作
    void resize(int newsize)
    {
        if (newsize <= MaxSize)
        {
            return; //如果新容量小于等于当前容量，则无需扩容
        }
        T* newData = new T[newsize]; //为新容量分配内存
        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i]; //将原有数据复制到新数组中
        }
        delete[] data; //释放原有内存
        data = newData; //更新指针
        MaxSize = newsize; //更新最大容量
        //长度不变，故无需修改
    }

    //插入操作——在指定位置i插入元素
        //注意位序和数组下标的关系   length属于位序，第i个中的i是位序，数组下标是i-1
    bool ListInsert(int i,const T& e)
    {
        if(i<0||i>length)
        {
           return false; 
        }
        if(length>=MaxSize)
        {
            resize(MaxSize*2); //如果当前长度达到最大容量，则将内存扩容为原来的两倍
        }
        for(int j=length;j>=i;j--)
        {
            data[j] = data[j-1]; //将元素向后移动
        }
        data[i-1]=e; //在指定位置插入新元素
        length++;
        return true;
    }

    //删除操作——删除指定位置i的元素
    bool ListDelete(int i,T& e)
    {
        if(i<0||i>length+1)
        {
            return false;
        }
        e=data[i-1]; //将要删除的元素赋值给e
        for(int j=i;j<length;j++)
        {
            data[j-1]=data[j]; //将元素向前移动
        }
        length--;
        return true;
    }

    //按位序查找
    bool GetElem(int i,T& e)
    {
        if(i<0||i>length)
        {
           return false; 
        }
        e=data[i-1]; //将指定位置的元素赋值给e
        return true;
    }

    //按值查找  返回其位序
    int LocateElem(const T& e)
    {
        for(int i=0;i<length;i++)
        {
            if(data[i]==e)
            {
                return i+1; //返回元素的位序
            }
        }
        return -1; //返回-1表示元素未找到
    }

    //重载[]运算符，提供数组下标访问功能
    T& operator[](int index) {
        return data[index];
    }

    const T& operator[](int index) const {
        return data[index];
    }

    //析构函数
    ~DynamicArray()
    {
        delete[] data;
    }
    
};