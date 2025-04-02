// since huffman tree is quite trivial,
// we only need a 1-d list to store it.
#include<bits/stdc++.h>
using namespace std;
typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

void Create(HuffmanTree &HT,int n){
    if(n<=1) return;
    int m=2*n-1;
    HT=new HTNode[m+1];
    //init
    for(int i=1;i<=m;i++){
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    for(int i=1;i<=n;i++){
        cin>>HT[i].weight;
    }
    for(int i=n+1;i<=m;i++){
        int s1,s2;
        /*  Select(HT,i-1,s1,s2)  */
        //choose two node with 0 parent and return the index s1,s2
        HT[s1].parent=i;
        HT[s2].parent=i;
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}
//huffman code
//actually vector is MUCH better 
typedef char **HuffmanCode;
void CreateHC(HuffmanTree HT,HuffmanCode &HC,int n){
    HC=new char*[n+1];
    char *cd = new char[n];
    cd[n-1]='\0';
    for(int i=1;i<=n;i++){
        int start=n-1;
        int c=i;
        int f=HT[i].parent;
        while(f!=0){
            --start;
            if(HT[f].lchild==c)cd[start]='0';
            else cd[start]='1';
            c=f;
            f=HT[f].parent;
        }
        HC[i]=new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    delete[] cd;
}
//fucking tortuous, why can't it be easier to use ptr?
