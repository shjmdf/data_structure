#include <iostream>
typedef struct _TreeNode{
    int data;
    struct _TreeNode* lchild;
    struct _TreeNode* rchild;
}BiTNode;
typedef BiTNode* Bi_tree;

//stack
typedef struct {
    BiTNode** base;    // 修改为BiTNode*类型的指针
    BiTNode** top;     // 修改为BiTNode*类型的指针
    int stacksize;
}sqstack;

void Initstack(sqstack &s){
    s.base = new BiTNode*[100];  // 存储树节点指针
    s.top = s.base;
    s.stacksize = 100;
}

bool Stack_empty(sqstack &s){
    return s.top == s.base;  // 修复返回值
}

void push(sqstack &s, BiTNode* p){
    if(s.top - s.base >= s.stacksize) return;  // 栈满判断
    *(s.top++) = p;  // 存入节点指针，top指针后移
}

void pop(sqstack &s, BiTNode* &q){  // 注意参数q应该是引用
    if(s.top == s.base) return;  // 栈空判断
    q = *(--s.top);  // top指针先前移，再取出节点指针
}
//中序遍历
void InOrder_Tranverse(Bi_tree T){
    sqstack s;
    Initstack(s);
    BiTNode* p=T;
    BiTNode* q=nullptr;
    while(p || !Stack_empty(s)){
        if(p){
            push(s,p);
            p=p->lchild;
        }
        else{
            pop(s,q);
            std::cout<<q->data;
            p=q->rchild;
        }
    }
    return;
}
//先序遍历 建立二叉链表
void Create_Bi_Tree(Bi_tree &T){
    char ch;
    std::cin>>ch;
    if (ch=='#') T=NULL;
    else{
        T=new BiTNode;
        T->data=ch;
        Create_Bi_Tree(T->lchild);
        Create_Bi_Tree(T->rchild);
    }
    return;
}
//copy二叉树
/*
void Copy(Bi_Tree T,Bi_Tree &newT){
    if (T==NULL) return;
    else{
        newT=new BiTNode;
        newT->data=T->data;
        Copy(T->lchild,newT->lchild);
        Copy(T->rchild,newT->rchild);
    }
}
*/