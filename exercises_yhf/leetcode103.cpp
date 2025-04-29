//题目没说清，有点红温，不写了
#include<bits/stdc++.h>
using namespace std;
int main(){

    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            int direction=0;//0 left-right, 1 right-left
            queue<TreeNode*> q;
            vector<vector<int> >ans;
            q.push(root);
            ans.push_back(vector<int>(root->val));
            direction=1-direction;
            while(!q.empty()){
                TreeNode* current=q.front();
                q.pop();
                vector<int> tempans;
                if(direction==0){
                    if(current->left!=nullptr){
                        tempans.push_back(current->left->val);
                        q.push(current->left);
                    }
                    if(current->right!=nullptr){
                        tempans.push_back(current->right->val);
                        q.push(current->right);
                    }
                }
                else{
                    if(current->right!=nullptr){
                        tempans.push_back(current->right->val);
                        q.push(current->right);
                    }
                    if(current->left!=nullptr){
                        tempans.push_back(current->left->val);
                        q.push(current->left);
                    }
                }
            }
        }
        
    };