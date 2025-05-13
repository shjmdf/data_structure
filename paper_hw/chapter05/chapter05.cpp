#include<bits/stdc++.h>
using namespace std;
int main(){

    return 0;
}
//1.
struct Node{
    int index;
    Node* left;
    Node* right;
};
int countnumbers(Node* root){
    int ans=0;
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr&&root->right==nullptr){
        return 1;
    }
    return countnumbers(root->left)+countnumbers(root->right);
}