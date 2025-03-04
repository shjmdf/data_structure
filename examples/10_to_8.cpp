#include<iostream>
struct Stack{
    int *base;
    int *top;
}S;
int main(){
    S.base=new int[100];
    S.top=S.base;
    int n;
    std::cin>>n;
    while(n){
        *S.top++=n%8;
        n/=8;
    }
    while(S.top!=S.base){
        std::cout<<*--S.top;
    }
    return 0;
}