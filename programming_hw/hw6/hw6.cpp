#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
struct BSTNode{
    int num_lchild;//左子树num的总和(不包括自己)
    int num;//当前节点的数量
    long idx;//当前节点的成绩
    BSTNode* lchild;
    BSTNode* rchild;
    BSTNode* parent;
    BSTNode(const long& val):num_lchild(0),num(1),idx(val),lchild(nullptr),rchild(nullptr),parent(nullptr){};
};
class BST{
protected:
    BSTNode* root;
    //清空
    void freeTree(BSTNode* node){
        if(node==nullptr) return;
        freeTree(node->lchild);
        freeTree(node->rchild);
        delete node;
    }
    //找最小
    BSTNode* findMin(BSTNode* node)const {
        if(node==nullptr) return nullptr;
        while(node->lchild!=nullptr) node=node->lchild;
        return node;
    }
    //最大
    BSTNode* findMax(BSTNode* node)const {
        if(node==nullptr) return nullptr;
        while(node->rchild!=nullptr) node=node->rchild;
        return node;
    }
public:
    BST():root(nullptr){}
    ~BST(){
        freeTree(root);
    }
    //判断是否在树里有相同成绩
    bool IdxinTree(long idx)const{
        BSTNode* node=root;
        while(node!=nullptr){
            if(node->idx==idx)return true;
            if(node->idx>idx){
                node=node->lchild;
                continue;
            }
            node=node->rchild;  
        }
        return false;
    }
    //插入
    void insert(long idx){
        BSTNode* node=root;
        if(IdxinTree(idx)){
            while(node->idx!=idx){
                //加左边数量
                if(node->idx>idx){
                    node->num_lchild++;
                    node=node->lchild;
                    continue;
                }
                node=node->rchild;
            }
            node->num++;
        }
        else while(node!=nullptr){
            
        }
    }

};
int main(){

    return 0;
}