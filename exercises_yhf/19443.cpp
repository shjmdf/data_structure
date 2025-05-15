#include<bits/stdc++.h>
using namespace std;
int x[1000][1000];
int main(){
    int n,m;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        x[a][a]++;
        x[b][b]++;
        x[a][b]--;
        x[b][a]--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<x[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}