#include<bits/stdc++.h>
using namespace std;
char pos[210][210];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool vis[210][210];
struct Node{
    int x;
    int y;
    int dis;
    Node(int sx,int sy,int sdis):x(sx),y(sy),dis(sdis){};
};
bool ValidPos(int tx,int ty,int r,int c);
int FindAns(int r, int c,pair<int,int> startpos,pair<int,int> endpos);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    int r,c;
    cin>>t;
    while(t--){
        cin>>r>>c;
        memset(vis,0,sizeof(vis));
        pair<int,int> startpos,endpos;
        for(int j=1;j<=r;j++){
            string s;
            cin>>s;
            for(int k=1;k<=c;k++){
                pos[j][k]=s[k-1];
                if(pos[j][k]=='S') startpos=make_pair(j,k);
                if(pos[j][k]=='E') endpos=make_pair(j,k);
            }
        }
        int ans=FindAns(r,c,startpos,endpos);
        if(ans==-1)cout<<"oop!"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
int FindAns(int r, int c,pair<int,int> startpos,pair<int,int> endpos){
    queue<Node> q;
    Node nstart(startpos.first,startpos.second,0);
    q.push(nstart);
    vis[startpos.first][startpos.second]=1;
    int ans=-1;
    while(!q.empty()){
        Node tempnode=q.front();
        q.pop();
        int tx=tempnode.x;
        int ty=tempnode.y;
        int tdis=tempnode.dis;
        //cout<<tx<<" "<<ty<<" "<<tdis<<endl;
        if(tx==endpos.first&&ty==endpos.second){
            ans=tdis;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=tx+dx[i];
            int ny=ty+dy[i];
            if(ValidPos(nx,ny,r,c)){
                vis[nx][ny]=1;
                Node temp(nx,ny,tdis+1);
                q.push(temp);
            }
        }
    }
    return ans;
}
bool ValidPos(int tx,int ty,int r,int c){
    if(tx>=1 && tx<=r && ty>=1 && ty<=c && pos[tx][ty]!='#'&& vis[tx][ty]==0)return true;
    return false;
}