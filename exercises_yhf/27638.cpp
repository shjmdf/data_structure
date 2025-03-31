#include<bits/stdc++.h>
struct Tree{
    int lc=-1;
    int rc=-1;
}tree[101];
using namespace std;
int dfs(int index,int val){
    if(tree[index].lc==-1 && tree[index].rc==-1){
        return val;
    }
    int temp1=-1,temp2=-1;
    if(tree[index].lc!=-1){
        temp1=dfs(tree[index].lc,val+1);
    }
    if(tree[index].rc!=-1){
        temp2=dfs(tree[index].rc,val+1);
    }
    return temp1>temp2?temp1:temp2;
}
int main(){
    int n,ans=-1,ans2=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tree[i].lc>>tree[i].rc;
        if(tree[i].lc==-1&&tree[i].rc==-1)ans2++;
    }
    for(int i=0;i<n;i++){
        int temp=dfs(i,0);
        ans=ans>temp?ans:temp;
    }
    cout<<ans<<" "<<ans2;
    return 0;
}