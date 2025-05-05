#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct FGKNode{
    int sym;//-1 for inner,-2 for NYT
    int num;
    int weight;
    FGKNode *left,*right,*parent;
    FGKNode(int w,int n,int s):
        sym(s),num(n),weight(w),
        left(nullptr),right(nullptr),
        parent(nullptr){}
};
class FGKTree{
private:
    FGKNode* root;
    FGKNode* NYT;
    vector<FGKNode*> nodes;
    int nextnumber;//下一个分配的编号
    void swapNodes(FGKNode* a, FGKNode* b){
        swap(a->sym,b->sym);
        swap(a->weight,b->weight);
        swap(a->num,b->num);
        //update ptr
        if(a->sym>=0) nodes[a->sym]=a;
        if(b->sym>=0) nodes[b->sym]=b;
    }
    //交换条件&交换
    FGKNode* node2swap(FGKNode* node){
        int weight=node->weight;
        FGKNode* swapNode=nullptr;
        vector<FGKNode*> allnodes=getAllNodes();
        for(FGKNode* curN: allnodes){
            if(curN!=node&&curN->weight==weight
                &&curN->num>node->num&&!isAncestor(curN,node)){
                    if(!swapNode||curN->num>swapNode->num){//维护兄弟性质
                        swapNode=curN;
                    }
                }
        }
        return swapNode;
    }
    bool isAncestor(FGKNode* a,FGKNode* b){
        while(b->parent){
            if(b->parent==a)return true;
            b=b->parent;
        }
        return false;
    }
    //遍历
    vector<FGKNode*> getAllNodes(){
        vector<FGKNode*> result;
        queue<FGKNode*> q;
        q.push(root);
        while(!q.empty()){
            FGKNode* node=q.front();
            q.pop();
            result.push_back(node);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        return result;
    }
    void deleteNode(FGKNode* node){
        if(!node) return;
        if(node->left)deleteNode(node->left);
        if(node->right)deleteNode(node->right);
        delete node;
    }
public:
    FGKTree(int numSymbols) : nextnumber(2*numSymbols-1){
        NYT=new FGKNode(0,nextnumber--,-2);
        root=NYT;
        nodes.resize(numSymbols+1,nullptr);
    }
    ~FGKTree() {
        deleteNode(root);
    }
    void update(int s){
        if(nodes[s]){
            updateExistSym(nodes[s]);
        }
        else{
            addNewSym(s);
        }
    }
    void addNewSym(int s){
        FGKNode* oldNYT=NYT;
        FGKNode* newNYT=new FGKNode(0,nextnumber--,-2);
        FGKNode* symNode=new FGKNode(1,nextnumber--,s);
        nodes[s]=symNode;
        oldNYT->left=newNYT;
        oldNYT->right=symNode;
        newNYT->parent=oldNYT;
        symNode->parent=oldNYT;
        oldNYT->sym=-1;
        oldNYT->weight=1;
        NYT=newNYT;
        updatePath(oldNYT->parent);
    }
    void updateExistSym(FGKNode* node){
        node->weight++;
        while(node!=root){
            FGKNode* swapNode=node2swap(node);
            if(swapNode&& swapNode!=node->parent){
                swapNodes(node,swapNode);
            }
            node=node->parent;
            node->weight++;
        }
    }
    void updatePath(FGKNode* node){
        while(node){
            node->weight++;
            node=node->parent;
        }
    }
    ll calculateLength(){
        ll total=0;
        function<void(FGKNode*,int)>dfs=[&](FGKNode* node,int depth){
            if(!node) return;
            //叶子节点，累加
            if(!node->left&&!node->right&&node->sym>=0){
                total+=node->weight*depth;
            }
            //NYT，计算
            if(node==NYT){
                total+=depth;
            }
            dfs(node->left,depth+1);
            dfs(node->right,depth+1);
        };
        dfs(root,0);
        return total;
    }
};
int main(){
    int n,m;
    int num;
    cin>>n>>m;
    FGKTree tree(n);
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        if(num) tree.update(num);
        else printf("%lld\n",tree.calculateLength());
    }
    return 0;
}