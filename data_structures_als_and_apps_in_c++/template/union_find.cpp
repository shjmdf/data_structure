#include<bits/stdc++.h>
using namespace std;
//基于树结构的并查集问题解决方案
int* parent;
int* treeRank; 
/*
vector<int> parent;
vector<int> treeRank;
*/
void init(int num){
    //初始化num棵树，每棵树一个元素
    parent=new int[num+1];
    treeRank=new int[num+1]();//这样就能初始化为0
    //vector式样初始化
    /*
    parent.resize(num+1);//resize为调整大小，原来的数据会保留
    treeRank.assign(num+1, 0);//assign等于直接替换
    */
    for(int e=1;e<=num;e++){
        parent[e]=e;//初始父节点都是自己
        //treeRank[e]=0;   // 初始秩为0
    }
}
int find(int element){
    //返回element所在的根
    if(parent[element]!=element){
        parent[element]=find(parent[element]);//递归压缩
    }
    return parent[element];
}
void unionSets(int x,int y){
    int rootX=find(x);
    int rootY=find(y);

    if(rootX!=rootY){
        if(treeRank[rootX]<treeRank[rootY]){
            parent[rootX]=rootY;
        }
        else if(treeRank[rootX]>treeRank[rootY]){
            parent[rootY]=rootX;
        }
        else{
            parent[rootY]=rootX;
            treeRank[rootX]++;
        }
    }
}
void cleanup() {
    delete[] parent;
    delete[] treeRank;
}

//路径压缩使每次查找后树变得更扁平
//按秩合并确保合并操作不会增加过多的树高
//两者结合，使并查集操作的时间复杂度接近于 O(1)，理论上是 O(α(n))，
//其中α是反阿克曼函数，这个函数增长极其缓慢。α(x)定义为最大的整数m使得Ackermann(m,m)≤x，一般α(x)<=4
