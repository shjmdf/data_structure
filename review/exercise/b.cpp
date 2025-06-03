#include<bits/stdc++.h>
using namespace std;
struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.first!=b.first)return a.first<b.first;
        else return a.second>b.second;
    }
};
priority_queue<pair<int, int> ,vector<pair<int, int> >,cmp> pq;
pair<int,int> reverse(int num);
int main(){
    int n;
    bool flag=false;
    pair<int, int> temp;
    cin>>n;
    for(int i=1;i<=n;i++){
        temp=reverse(i);
        pq.push(temp);
    }
    while(!pq.empty()){
        temp=pq.top();
        pq.pop();
        if(flag)cout<<" "<<temp.second;
        else{
            cout<<temp.second;
            flag=true;
        }
    }
    return 0;
}
pair<int,int> reverse(int num){
    vector<int> ls;
    int temp=num;
    int l=0,ans=0;
    while(num){
        ls.push_back(num%10);
        l++;
        num/=10;
    }
    for(auto n:ls){
        ans+=n*pow(10,l);
        l--;
    }
    //cout<<ans;
    return make_pair(ans,temp);
}