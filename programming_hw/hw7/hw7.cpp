#include<bits/stdc++.h>
using namespace std;
#define MINIMUM LONG_MIN
#define MAXIMUM LONG_MAX
typedef struct Node{
    int num;
    long* nodes;
    Node(int n):num(n){
        if(n>0){
            nodes=new long[num];
        }
        else{
            nodes=nullptr;
            num=0;
        }
    }
    ~Node(){
        delete[] nodes;
    }
}Arr;
Arr* mergesort(int l,int r,Arr* root);
int main(){
    int n;
    cin>>n;
    Arr root(n);
    //input,root is the main one
    for(int i=0;i<n;++i){
        cin>>root.nodes[i];
    }
    Arr* ans=mergesort(0,n-1,&root);
    for(int i=0;i<n;++i){
        cout<<ans->nodes[i]<<" ";
    }
    delete ans;
    return 0;
}
Arr* mergesort(int l,int r,Arr* root){
    //return
    if(l==r) {
        Arr* rroot=new Arr(1);
        rroot->nodes[0]=root->nodes[l];
        return rroot;
    }
    int mid=l+(r-l)/2;
    Arr* a=mergesort(l,mid,root);
    Arr* b=mergesort(mid+1,r,root);
    int lnum=a->num;
    int rnum=b->num;
    int ls=0,rs=0,rets=0;
    Arr* ret=new Arr(lnum+rnum);
    while(ls<lnum||rs<rnum){
        if(ls==lnum){
            while(rs<rnum){
                ret->nodes[rets++]=b->nodes[rs++];
            }
            break;
        }
        if(rs==rnum){
            while(ls<lnum){
            ret->nodes[rets++]=a->nodes[ls++];
            }
            break;
        }
        if(a->nodes[ls]<=b->nodes[rs]){
            ret->nodes[rets++]=a->nodes[ls++];
        }
        else{
            ret->nodes[rets++]=b->nodes[rs++];
        }
    }
    delete a;
    delete b;
    return ret;
}