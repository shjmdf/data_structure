#include <iostream>
//定义链表所需要的结构体
struct Node{
    int data;
    Node* next;
};
//沿着头指针展开搜索
Node* search(Node* head, int x){
    Node* current{head};
    for (int i=1;i<=x;i++){
        if((*current).next==nullptr){
            return nullptr;
        }
        current=(*current).next;
    }
    return current;
}
int main(){
    //创建头指针
    Node* head{new Node{0}};
    //当前指针
    Node* current{head};
    //10个节点
    for(int i=1;i<10;i++){
        (*current).next=new Node{i};
        current=(*current).next;
    }
    (*current).next=nullptr;
   //找到第5个节点
    Node* result = search(head, 5);
    if (result != nullptr) { // 检查 result 是否为 nullptr
        std::cout<<(*result).data;
    }
    return 0;
}
// 第17行和第20行可能会报警，因为在访问指针 current 和 result 的成员变量之前，没有检查这些指针是否为 nullptr。
// 如果指针为 nullptr，访问其成员变量会导致程序崩溃。