const int MAXSIZE=100;
typedef struct {
    int stacksize;
    int* base;
    int* top;

}sqstack;
//initialize
void Initstack(sqstack &s){
    s.base=new int[MAXSIZE];
    //if(!s.base)exit();
    s.top=s.base;
    s.stacksize=MAXSIZE;
    return;
}
//push
void push(sqstack &s,int e){
    if(s.top-s.base==s.stacksize)return;
    *(s.top)=e;
    s.top++;
    return;
}
//pop
void pop(sqstack &s,int &e){
    if(s.top==s.base)return;
    s.top--;
    e=*s.top;
    return;
}
//top
void top(sqstack &s,int &e){
    if(s.top==s.base)return;
    e=*--s.top;
    s.top++;
    return;
}
