#include<bits/stdc++.h>
int a[102][102];//地图
bool visited[102][102];//访问
int cost[12][12];//建模后得到的每一个节点到彼此的距离
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
//状压
int dp[12][1<<12]; 
bool vis[12][1<<12];

using namespace std;
priority_queue<pair<int, int> >pq;
vector<pair<pair<int, int>, int>> food;
int dfs(int pos,int mask);
void bfs(int i,int j,int steps,int start_idx);
int main(){
    int m,n,dots=0;
    int ans=0;
    //input
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]>0){
                pq.push(make_pair(i,j));//位置，供dfs
                food.push_back(make_pair(make_pair(i,j),a[i][j]));//food的位置，价值
                dots++;//统计多少个食物
                if(a[i][j]>ans)ans=a[i][j];//初始的答案
            }
        }
    }
    //建图
    //init cost
    for(int i=0;i<dots;i++){
        for(int j=0;j<dots;j++){
            if(i!=j) cost[i][j]=INT_MAX;
        }
    }
    //bfs
    for(int _n=0;_n<int(food.size());_n++){//每一个食物开始
        memset(visited, 0, sizeof(visited));
        int i=food[_n].first.first;
        int j=food[_n].first.second;
        bfs(i,j,0,_n);//从这个点开始
    }
    //初始化
    memset(vis,0,sizeof(vis));
    memset(dp,-0x3f,sizeof(dp));
    //搜索
    for(int i=0;i<int(food.size());i++){
        int current=food[i].second+dfs(i,1<<i);
        ans=max(ans,current);
    }
    cout<<ans<<endl;
    return 0;
}
void bfs(int i,int j,int steps,int start_idx){

    queue<pair<pair<int, int> ,int>> q;
    q.push(make_pair(make_pair(i,j),steps));
    visited[i][j]=1;

    while(!q.empty()){
        //取点
        pair<pair<int, int>, int> current_node=q.front();
        q.pop();

        //更新
        int current_i=current_node.first.first;
        int current_j=current_node.first.second;
        int current_steps=current_node.second;

        for(int food_idx=0;food_idx<int(food.size());food_idx++) {
            if(food_idx!=start_idx&& 
               food[food_idx].first.first==current_i&& 
               food[food_idx].first.second==current_j) {
                // 更新到这个食物点的最小距离
                cost[start_idx][food_idx]=current_steps;
            }
        }
        //扩展
        for(int _n=0;_n<4;_n++){
            int next_i=current_i+dx[_n];
            int next_j=current_j+dy[_n];
            if(a[next_i][next_j]!=-1&&!visited[next_i][next_j]){
                visited[next_i][next_j] = 1;
                q.push(make_pair(make_pair(next_i, next_j),current_steps+1));
            }
        }
    }
    return;
}


//状压dfs
int dfs(int pos,int mask){
    if (mask==(1<<food.size())-1) return 0;
    //记忆化
    if (vis[pos][mask]) return dp[pos][mask];
    vis[pos][mask]=true;
    int result=0; //当前最大食物
    
    //尝试从当前位置到其他所有食物点
    for(int next=0;next<int(food.size());next++){
        if((mask>>next)&1||cost[pos][next]==INT_MAX) continue;
        int gain=food[next].second-cost[pos][next];
        int next_result=dfs(next,mask|(1<<next));
        //更新
        result=max(result,gain+next_result);
    }
    
    return dp[pos][mask]=result;
}
