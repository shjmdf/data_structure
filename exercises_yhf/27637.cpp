#include<bits/stdc++.h>
struct TreeNode{
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
TreeNode* buildTree(const string& s, int& pos) {
    if (pos >= s.length() || s[pos] == '*') {
        if (pos < s.length() && s[pos] == '*') pos++;
        return NULL;
    }
    
    TreeNode* root = new TreeNode(s[pos++]);
    
    if (pos < s.length() && s[pos] == '(') {
        pos++; 
        
        root->left = buildTree(s, pos);
        
        if (pos < s.length() && s[pos] == ',') {
            pos++; 
            

            root->right = buildTree(s, pos);
        }
        
        if (pos < s.length() && s[pos] == ')') {
            pos++;
        }
    }
    
    return root;
}
string preOrder(TreeNode* Node){
    string result="";

    result+=Node->val;

    if(Node->left!=NULL){
        result+=preOrder(Node->left);
    }

    if(Node->right!=NULL){
        result+=preOrder(Node->right);
    }
    return result;
}
string inOrder(TreeNode* Node){
    string result="";
    if(Node->left!=NULL){
        result+=inOrder(Node->left);
    }
    result+=Node->val;
    if(Node->right!=NULL){
        result+=inOrder(Node->right);
    }
    return result;
}
int main(){
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        int pos=0;
        TreeNode* tree=buildTree(s,pos);
        string preO,inO;
        preO=preOrder(tree);
        inO=inOrder(tree);
        cout<<preO<<endl;
        cout<<inO<<endl;
    }
    return 0;
}