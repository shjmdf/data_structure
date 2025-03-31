#include<bits/stdc++.h>
using namespace std;
void game(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > nums(n+1,vector<int>(m+1,0));
    vector<vector<int> > adds(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>nums[i][j];
        }
        //排序
        sort(nums[i].begin()+1,nums[i].end());
        //与第一个的差值
        for(int j=1;j<=m;j++){
            adds[i][j]=nums[i][j]-nums[i][1];
        }
    }
    int ans=0;
    //预处理一个ans
    for(int i=1;i<=n;i++){
        ans+=nums[i][1];
    }
    cout<<ans<<" ";
    m--;
    priority_queue<int> q;
    //into a pq
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m;j++){
            q.push(-adds[i][j]);
        }
    }
    while(m>0){
        cout<<ans+(-q.top())<<" ";
        q.pop();
        m--;
    }
}
int main(){
    int num;
    cin>>num;
    for(int i=1;i<=num;++i){
        game();
    }
    return 0;
}
/*
1
2 3
1 2 3---0 1 2
2 2 3---0 0 1 
*/