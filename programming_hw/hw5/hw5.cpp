#include<bits/stdc++.h>
using namespace std;
long long HT(const vector<long long> &st,const set<long long> &idx);
int main(){
    long long n,m;
    cin>>n>>m;
    //存储词频
    vector<long long> freq(n+1,0);
    set<long long> idx;
    //结束符号init
    freq[0]=1;
    idx.insert(0);

    for(long long i=1;i<=m;i++){
        long long ch;
        cin>>ch;
        if(ch!=0){
            freq[ch]++;//词频
            idx.insert(ch);//下标
        }
         
        else {
            cout<<HT(freq,idx)<<endl;
        }
    }
    return 0;
}
long long HT(const vector<long long> &st,const set<long long> &idx) {
    long long total=0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(auto i:idx){
        pq.push(st[i]);//压入优先队列
    }
    //滚动
    while(pq.size()>1){
        long long a=pq.top();
        pq.pop();
        long long b=pq.top();
        pq.pop();
        pq.push(a+b);
        total+=a+b;//统计
    }
    return total;
}