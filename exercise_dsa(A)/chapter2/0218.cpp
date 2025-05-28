#include<bits/stdc++.h>
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int a[31][31];
int main(){
    int n,ans;
    cin>>n>>ans;
    int i=1,x=1,y=1,d=0;
    a[1][1]=1;
    while(i<ans){
        int tx=x+dx[d];
        int ty=y+dy[d];
        //cout<<tx<<" "<<ty<<endl;
        if(tx>=1&&tx<=n&&ty>=1&&ty<=n){
            if(a[tx][ty]==0){//合法
                a[tx][ty]=++i;
                x=tx;
                y=ty;
                continue;
            }
        }
        //非法
        d=(d+1)%4;
        tx=x+dx[d];
        ty=y+dy[d];
        a[tx][ty]=++i;
        x=tx;
        y=ty;
    }
    cout<<y<<" "<<x;
    return 0;
}