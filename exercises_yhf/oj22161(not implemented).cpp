#include<bits/stdc++.h>
using namespace std;
struct Node{
    char ch;//if the leaf, true ch;else minimal index
    int freq;
    Node* left;
    Node* right;
};
struct CompareNode{
    bool operator()(Node* a,Node* b){
        return a->freq>b->freq;
    }
};
void GenerateTree(Node* root,string code,map<char,string>& codes){
    if(root==nullptr)return;
    if(root->left==nullptr&& root->right==nullptr);
}
int main(){
    int n;
    

    return 0;
}