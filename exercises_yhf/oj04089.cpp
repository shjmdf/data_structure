#include<bits/stdc++.h>
using namespace std;
struct Node{
    short num;
    Node* parent;
    vector<Node*> kids=vector<Node*>(10,nullptr);
};
struct ComparePair{
    bool operator()(const pair<string, int>&a, const pair<string, int>&b)const{
        return a.second<b.second;
    }
};
bool tree(string s,Node* root);
void freeNode(Node* root){
    if(root==nullptr) return;
    for(auto kid: root->kids){
        freeNode(kid);
    }
    free(root);
}
void task(int num){
    Node* root=new Node();
    string s;
    priority_queue<pair<string, int>,vector<pair<string, int>>, ComparePair> pq;
    for(int i=1;i<=num;i++){
        cin>>s;
        pq.push(make_pair(s,s.length()));
    }
    while(!pq.empty()){
        s=pq.top().first;
        pq.pop();
        if(tree(s,root)){
            cout<<"NO"<<endl;
            freeNode(root);
            return;
        }
    }
    cout<<"YES"<<endl;
    freeNode(root);
    return;
}
bool tree(string s,Node* root){
    int len=int(s.length());
    Node* current=root;
    bool flag=true;
    for(int i=0;i<len;i++){
        short num=short(s[i]-'0');
        if(current->kids[num]==nullptr){
            Node* n=new Node();
            n->parent=current;
            current->kids[num]=n;
            flag=false;
            current=n;
        }
        else{
            current=current->kids[num];
        }
    }
    return flag;
}
int main(){
    int n;
    int quest;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>quest;
        task(quest);
    }
    return 0;
}