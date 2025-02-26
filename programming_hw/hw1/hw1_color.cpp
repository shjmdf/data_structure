#include<iostream>
#include <cstring>
using namespace std;

void input(int n,int k,bool (&graph)[100][100]){//输入边的信息
    int a,b;//a,b作为临时变量存储输入的两个点，建立边的信息
    for (int i=1;i<=k;i++){
        cin>>a>>b;
        graph[a][b]=graph[b][a]=1;//无向图需要两个方向都要标记
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    */
}
bool is_adjacent(int a,int b, bool (&graph)[100][100]) {//判断两个点是否相邻
    if(graph[a][b]==1){
        return true;
    }
    else{
        return false;
    }
}
bool paint_color(int m,bool (&graph)[100][100],int (&color)[100],int n,int x){
    if(x>n){
        return true;    
    }//所有点都已经涂色
    for(int i=1;i<=m;i++){
        bool flag=0;
        for(int j=1;j<=n;j++){
            if(is_adjacent(x,j,graph)&&j!=x&&color[j]==i){
                flag=1;
            }//如果相邻的点已经涂色，且颜色相同，跳过
        }
        if(flag){
            continue;
        }//（改进内容）之前把后续语句放入第二重循环中，故而出错
        color[x]=i;
        if(paint_color(m,graph,color,n,x+1)){
            return true;
        }//递归调用，涂色下一个点
        color[x]=-1;//回溯
    }
    return false;
}
int main(){
    int n,k,m=1;//n个点，k种颜色,m表示最小的颜色数
    bool graph[100][100];//图的邻接矩阵,1表示相邻，0表示不相邻
    int color[100];//每个点的颜色

    memset(graph,0,sizeof(graph));//初始化图
    memset(color,-1,sizeof(color));//初始化颜色,-1表示未涂色

    cin>>n>>k;//输入点数和边数

    input(n,k,graph);//输入边的信息
    
    for(m=1;m<=n;m++){
        memset(color,-1,sizeof(color));//初始化颜色,-1表示未涂色
        if(paint_color(m,graph,color,n,1)){
            /*
            for(int i=1;i<=n;i++){
                cout<<color[i]<<" ";
            }
            */
            //debug
            cout<<m<<endl;
            break;
        }
    }
    return 0;
}