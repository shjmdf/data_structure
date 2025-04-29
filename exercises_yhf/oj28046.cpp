#include<bits/stdc++.h>
using namespace std;
int n;
struct Node{
    vector<int> adjacent_index;
    string word;
};
vector<Node> nodes;
bool adjacent_word(string a,string b){
    int diff=0;
    for(int i=0;i<=3;i++){
        if(a[i]^b[i]){
            diff++;
        }
    }
    if(diff>=2)return false;
    return true;
}
string start,target;
void dijkstra(int start_index,int target_index){
    vector<int> dis(n+1);
    vector<int> parent(n+1,-1);
    fill(dis.begin(),dis.end(),INT_MAX);
    dis[start_index]=0;
    vector<bool> visited(n+1,0);
    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;
    pq.push(make_pair(0,start_index));
    while(!pq.empty()){
        int index=pq.top().second;
        pq.pop();
        if(index==target_index)break;
        if(visited[index])continue;
        visited[index]=1;
        for(int _=0;_<nodes[index].adjacent_index.size();_++){
            if(dis[index] + 1 <dis[nodes[index].adjacent_index[_]]){
                dis[nodes[index].adjacent_index[_]]=dis[index]+1;
                parent[nodes[index].adjacent_index[_]]=index;
                pq.push(make_pair(dis[nodes[index].adjacent_index[_]], nodes[index].adjacent_index[_]));
            }
        }
    }
    if(dis[target_index]==INT_MAX){
        cout<<"NO"<<endl;
        return;
    }
    else{
        stack<string>paths;
        int cidx=target_index;
        do{
            paths.push(nodes[cidx].word);
            cidx=parent[cidx];
        }while(cidx!=-1);
        while(!paths.empty()){
            cout<<paths.top()<<" ";
            paths.pop();
        }
    }
    return;
}
int main(){
    cin>>n;
    nodes.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>nodes[i].word;
    }
    cin>>start>>target;

    int stindex=0,tgindex=0;
    for(int i=1;i<=n;i++){
        if(nodes[i].word==start) stindex=i;
        if(nodes[i].word==target) tgindex=i;
    }
    if(!(stindex&&tgindex)){
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if (adjacent_word(nodes[i].word,nodes[j].word)){
                nodes[i].adjacent_index.push_back(j);
                nodes[j].adjacent_index.push_back(i);
            }
        }
    }
    dijkstra(stindex,tgindex);
    return 0;
}