#include<iostream>
//TASK 2
/*
class Stack{
    public:
        Stack(){
            base=new int[101];
            stacksize=101;
            top=base;
        }
        ~Stack(){
            delete []base;
        }
        bool isEmpty(){
            if(top==base)return true;
            return false;
        }
        void push(int num){
            if(top-base>=stacksize)return;
            *top++=num;
        }
        int pop(){
            if (isEmpty())return -1;
            return *--top;
        }
        
    private:
        int stacksize;
        int* top;
        int* base;
};

void de_to_b(int dec){
    Stack s;
    while(dec>0){
        s.push(dec%2);
        dec/=2;
    }
    while(!s.isEmpty()){
        std::cout<<s.pop();
    }
}
int main(){
    int dec;
    std::cin>>dec;
    de_to_b(dec);
    return 0;
}
*/
//TASK 7
/*

class Stack{
    public:
        virtual bool isEmpty1() {}
        virtual bool isEmpty2() {}
        bool isFull(){
            return top_1+1==top_2;
        }
        void push_1(int num){
            if(!isFull()){
                *top_1++=num;
            }
        }
        int pop1(){
            if(!isEmpty1()){
                return *--top_1;
            }
        }
        int top(){
            int num;
            if(!isEmpty1()){
                num=*--top_1;
                top_1++;
            }
            return num;
        }
    private:
        int stacksize=100;
        int* top_1;
        int* top_2;
};
*/
//TASK 9
/*
#define m 100
int rear,quelen;
int sequ[m];
bool isFull(){
    return quelen==m;
}
void push(int num){
    if (rear==m){
        if(!isFull())rear=0;
        else printf("error");
    }
    sequ[rear]=num;
    rear++;
    quelen++;
}
int pop(){
    if(quelen==0){
        printf("error");
        return -1;
    }
    int front=(rear-quelen+1+m)%m;
    int temp=sequ[front];
    quelen--;
    return temp;
}
*/