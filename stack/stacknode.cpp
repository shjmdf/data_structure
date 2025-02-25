typedef struct StackNode{
    int data;
    StackNode* next;
}StackNode,*LinkStack;

//Init
//in main function
//s=new StackNode{0};
//s.next=nullptr;

//Push
void push(StackNode** s,int e){
    StackNode* p = new StackNode;
    (*p).data=e;
    (*p).next=*s;
    *s=p;
    return;
}
