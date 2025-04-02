#include<bits/stdc++.h>
using namespace std;
int* parent;
int* treeRank; 

void init(int num){
    //初始化num棵树，每棵树一个元素
    parent=new int[num+1];
    treeRank=new int[num+1]();

    for(int e=1;e<=num;e++){
        parent[e]=e;//初始父节点都是自己
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
int main(){
    int n,m;
    cin>>n>>m;
    int z,x,y;
    init(n);
    for(int i=1;i<=m;i++){
        cin>>z>>x>>y;
        if(z==1){
            unionSets(x,y);
        }
        if(z==2){
            if(find(x)==find(y)){
                cout<<"Y"<<endl;
            }
            else{
                cout<<"N"<<endl;
            }
        }
    }
    cleanup();
    return 0;
}