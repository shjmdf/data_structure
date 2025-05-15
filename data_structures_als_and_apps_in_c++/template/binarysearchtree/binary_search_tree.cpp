/*
二叉搜索树：左树的值<中<右树的值
索引二叉搜索树（indexed BST）
每个节点中增加一个leftSize域，这个域的值是该节点左子树的元素个数
 */

/*
二叉搜索树用链表表示
*/
#include<bits/stdc++.h>
using namespace std;
struct BSTNode{
    int key;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    BSTNode(const int& value) : key(value), left(nullptr), right(nullptr), parent(nullptr) {}
};
class BinarySearchTree{
protected:
    BSTNode* root;
    //中序遍历
    void inorederTraversal(BSTNode* root)const {
        if(root==nullptr) return;
        inorederTraversal(root->left);
        cout<<root->key<<" ";
        inorederTraversal(root->right);
    }
    //查找最小值节点
    BSTNode* findMin(BSTNode* node) const {
        if(node==nullptr) return nullptr;
        while(node->left!=nullptr) node=node->left;
        return node;
    }
    BSTNode* findMax(BSTNode* node) const {
        if(node==nullptr) return nullptr;
        while(node->right!=nullptr) node=node->right;
        return node;
    }
    void freeTree(BSTNode* node) const{
        if(node==nullptr) return;
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
public:
    BinarySearchTree():root(nullptr){}
    ~BinarySearchTree(){
        freeTree(root);
    }
    //插入数据
    void insert(const int& key){
        BSTNode* newnode=new BSTNode(key);
        if(root==nullptr){
            root=newnode;
            return;
        }
        BSTNode* current=root;
        BSTNode* parent=nullptr;
        while(current!=nullptr){
            parent=current;
            if(key>current->key){
                current=current->right;
            }
            else current=current->left;
        }
        newnode->parent=parent;
        if(newnode->key>parent->key){
            parent->right=newnode;
        }
        else parent->left=newnode;
    }

    BSTNode* search(const int& key) const {
        BSTNode* current=root;
        while(current!=nullptr&& current->key!=key){
            if(key<current->key){
                current=current->left;
            }
            else current=current->right;
        }
        return current;
    }
    void remove(const int& key){
        BSTNode* node=search(key);
        if(node==nullptr) return;
        //如果为叶节点
        if(node->left==nullptr&&node->right==nullptr){
            if(node==root)root=nullptr;
            else{
                if(node->parent->left==node)
                    node->parent->left=nullptr;
                else node->parent->right=nullptr;
            }
            delete node;
        }
        //左无右有
        if(node->left==nullptr){
            if(node==root){
                root=node->right;
                node->right->parent=nullptr;
            }
            else {
                node->right->parent=node->parent;
                if(node->parent->left==node){
                    node->parent->left=node->right;
                }
                else node->parent->right=node->right;
            }
            delete node;
        }
        //右有左无
        else if(node->right==nullptr){
            if(node==root){
                root=node->left;
                node->left->parent=nullptr;
            }
            else {
                node->left->parent=node->parent;
                if(node->parent->left==node){
                    node->parent->left=node->left;
                }
                else node->parent->right=node->left;
            }
            delete node;
        }
        //两个子节点
        else{
            BSTNode* successor=findMin(node->right);
            node->key=successor->key;
            if(successor->parent->left==successor){
                successor->parent->left=successor->right;
            }
            else successor->parent->right=successor->right;
            if(successor->right)
                successor->right->parent=successor->parent;
            delete successor;
        }
    }
    //最小值
    int getMin() const{
        BSTNode* node=findMin(root);
        return node?node->key:int();
    }
    //最大值
    int getMax() const{
        BSTNode* node=findMax(root);
        return node?node->key:int();
    }
    void inOrder()const{
        inorederTraversal(root);
        return;
    }
};
