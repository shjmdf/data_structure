#include<bits/stdc++.h>
using namespace std;
int n,m,max_value=-INT_MAX;
int maxfood;//最大食物，剪枝
int a[102][102];//防止溢出
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int x,int y,int value,int remaining){
    if(value+remaining<=max_value) return;//没有潜力
    int temp=a[x][y];
    if(a[x][y]>0){
        value+=a[x][y]-1;//吃掉，如果没有访问
        remaining-=a[x][y];
        a[x][y]=0;//标记已经吃掉
    }
    else value-=1;//没有可以吃的

    max_value=max(max_value,value);//如果当下比最大值高，则存储

    for(int i=0;i<4;i++){//四向
        int temp_x=x+dx[i];
        int temp_y=y+dy[i];
        if(a[temp_x][temp_y]!=-1){//不是墙壁
            dfs(temp_x,temp_y,value,remaining);//搜索
        }
    }
    a[x][y]=temp;//恢复
}
int main(){
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> startPoints;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]>0){
                maxfood+=a[i][j];
                startPoints.push_back({a[i][j],{i,j}});
            } 
        }
    }
    //从最大的开始搜
    sort(startPoints.begin(), startPoints.end(), greater<>());
    for(auto &p:startPoints) {
        int i=p.second.first;
        int j=p.second.second;
        dfs(i,j,1,maxfood);
    }
    cout<<max_value<<endl;
    return 0;
}