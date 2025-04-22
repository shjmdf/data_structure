#include <bits/stdc++.h>

using namespace std;

struct Node{
    int rightpos;
    long long value;
};

using Tuple=tuple< long long, int, int>;
using ll=long long;
vector<Node> Nodes;

//trivial way
bool validlist(vector<Node>& Nodes){
    for(int i=0;i<int(Nodes.size()-1);i++){
        if(Nodes[i].value>Nodes[i+1].value)return false;
    }
    return true;
}
// init a nodelist
void init(vector<int>& nums,vector<Node>& Nodes){
    for(int i=0;i<int(nums.size()-1);i++){
        Node temp_node;
        temp_node.rightpos=i+1;
        temp_node.value=(long long)nums[i];
        Nodes.push_back(temp_node);
    }
}
void addpq(vector<Node>& Nodes,priority_queue< Tuple, vector<Tuple>, greater<> >& pq){
    for(int i=0;i<int(Nodes.size()-1);i++){
        pq.push({(long long)(Nodes[i].value+Nodes[i+1].value),i,i+1});
    }
}
int minimumPairRemoval(vector<int>& nums){
    //init everything
    if (nums.size()<=1) return 0;

    int operations=0;
    multiset<ll>
    init(nums,Nodes);
    if(validlist(Nodes)) return 0;


    while(true){
       
    }
    return operations;
}