#include<bits/stdc++.h>
using namespace std;

template<class T>
class arraystack :public stack<T>// 如果要自己实现栈，不需要继承 stack<T>
{
private:
    T* stack;          // 存储元素的数组
    int stackTop;      // 栈顶指针
    int capacity;      // 当前容量
    
public:
    // 构造函数
    arraystack(int initialCapacity=10) {
        stack = new T[initialCapacity];
        capacity = initialCapacity;
        stackTop = -1;  // 初始化为空栈
    }
    
    // 析构函数
    ~arraystack() {
        delete[] stack;
    }
    
    // 判断栈是否为空
    bool empty() const {
        return stackTop == -1;
    }
    
    // 返回栈中元素个数
    int size() const {
        return stackTop + 1;
    }
    
    // 返回栈顶元素的引用
    T& top() {
        if(stackTop == -1)
            throw std::runtime_error("Stack is empty");
        return stack[stackTop];
    }
    
    // 弹出栈顶元素
    void pop() {
        if(stackTop == -1)
            throw std::runtime_error("Stack is empty");
        // 正确的方式是简单递减栈顶指针
        stackTop--;  // 移除栈顶元素
    }
    
    // 将元素压入栈
    void push(const T& element) {
        // 检查是否需要扩容
        if (stackTop == capacity - 1) {
            // 栈已满，需要扩容
            capacity *= 2;
            T* newStack = new T[capacity];
            // 复制旧数据
            for (int i = 0; i <= stackTop; i++) {
                newStack[i] = stack[i];
            }
            // 释放旧内存并更新指针
            delete[] stack;
            stack = newStack;
        }
        // 将元素添加到栈顶
        stack[++stackTop] = element;
    }
};