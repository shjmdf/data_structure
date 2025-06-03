#include<bits/stdc++.h>
using namespace std;
int num[110];
int ans;
int main(){
    int n;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        ans=1;
        memset(num,0,sizeof(num));
        num[0]=1;
        int len=s.length();
        if(len==1){
            cout<<1;
            if(i!=n)cout<<endl;
            continue;
        }
        for(int j=1;j<len;j++){
            if(int(s[j]-'0')>=int(s[j-1]-'0')){
                num[j]=num[j-1]+1;
                if(num[j]>ans){
                    ans=num[j];
                }
            }
            else{
                num[j]=1;
            }
        }
        cout<<ans;
        if(i!=n)cout<<endl;
    }
    return 0;
}