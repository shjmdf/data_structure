/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            int num=k;
            TreeNode* node=root;
            while(1){
                if(num_of_son(node->left)+1==num)break;
                if(num_of_son(node->left)>=num){
                    node=node->left;
                    continue;
                }
                else{
                    num-=num_of_son(node->left);
                    node=node->right;
                }
            }
            return node->val;
        }
        int num_of_son(TreeNode* node){
            if(node==nullptr)return 0;
            return num_of_son(node->left)+num_of_son(node->right);
        }
        
    };
*/