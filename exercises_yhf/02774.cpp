#include<bits/stdc++.h>
int a[10010];
int maxn=-INT_MAX;
int minlength;
int maxlength;
int ans;
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(maxn<a[i])maxn=a[i];
    }
    //init
    minlength=0;
    maxlength=maxn;
    //初始就行
    for(int i=1;i<=n;i++){
        ans+=a[i]/maxn;
    }
    //cout<<ans;
    if(ans>=k){
        cout<<maxn;
    }
    else while(1){
        //cout<<ans<<' '<<minlength<<' '<<maxlength;
        if(maxlength==0){//最小的也不行
            cout<<0;
            break;
        }
        if(maxlength==minlength){//重合
            cout<<minlength;
            break;
        }
        if(maxlength==minlength+1){
            ans=0;//重新0
            for(int i=1;i<=n;i++){
            ans+=a[i]/maxlength;
            }
            if(ans>=k){
                cout<<maxlength;
                break;
            }
            cout<<minlength;
            break;
        }
        if(ans>=k){
        }
        int length=(minlength+maxlength)/2;
        ans=0;//重新0
        for(int i=1;i<=n;i++){
            ans+=a[i]/length;
        }
        if(ans>=k){
            minlength=length;
        }
        else{
            maxlength=length;
        }
    }
    return 0;
}