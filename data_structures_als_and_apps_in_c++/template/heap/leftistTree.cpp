//堆结构是一种隐式数据结构
//但是面对优先队列中需要合并的时候，我们就要其他的数据结构，如：左高树（leftist tree）
//external node(代替树中的空子树)
//令s(x)是从x到其子树的外部节点的所有路径中最短的一条
/*
若x为exnode：s=0
else： s(x)=min{s(x.L),s(x.R)}+1
定义：一棵二叉树是高度优先左高树(HBLT) == 其每一个内部节点的左孩子的s值>=右孩子的s值

若x为exnode：w=0
else: w(x)=w(x.L)+w(x.R)+1
定义：一棵二叉树是重量优先左高树(WBLT) == 其每一个内部节点的左孩子的w值>=右孩子的w值
*/

/*
左高树（Leftist Heap），又称左式堆，是一种支持高效合并的优先队列数据结构。
其核心特性是“左倾”，即每个节点的左子树比右子树“高”，
从而确保合并操作的时间复杂度为 O(logn).
*/
/*
关键概念：NPL（Null Path Length）
定义：NPL 是从节点到最近缺少至少一个子节点的后代节点的路径长度。
叶子节点的 NPL 为 0（因为它没有子节点）。
内部节点的 NPL 是 1 + min(左子节点 NPL, 右子节点 NPL)。
意义：NPL 衡量树的“右路径”长度。左高树要求每个节点的左子节点 NPL ≥ 右子节点 NPL，确保树向左倾斜。
*/
#include<iostream>
#include<stdexcept>
using std::swap;
/*
左高树的性质
结构性质：对任意节点，左子树的 NPL ≥ 右子树的 NPL。
堆性质：父节点的键值 ≤ 子节点键值（最小堆为例）。
*/
struct LeftistNode{
    int key;
    int npl;//null path length
    LeftistNode* left;
    LeftistNode* right;
    LeftistNode(int val): key(val),npl(0),left(nullptr),right(nullptr){};
};
class LeftistHeap{
private:
    LeftistNode* root;
    /*
    合并操作（核心）
    合并两个左高树的过程如下：
    比较根节点：将较小的根作为新根（假设最小堆）。
    递归合并：将较大根的右子树与另一棵树合并。
    调整子树：合并后，若左子树的 NPL < 右子树的 NPL，则交换左右子树。
    更新 NPL：当前节点的 NPL = 1 + min(左子 NPL, 右子 NPL)。
    */
    LeftistNode* merge(LeftistNode* heap1,LeftistNode* heap2){
        if(heap1==nullptr) return heap2;
        if(heap2==nullptr) return heap1;

        if(heap1->key>heap2->key){
            std::swap(heap1,heap2);
        }
        heap1->right=merge(heap1->right,heap2);
        if(heap1->left==nullptr || heap1->left->npl<heap2->right->npl){
            std::swap(heap1->left,heap1->right);
        }
        return heap1;
    }
    //析构辅助
    void clear(LeftistNode* node){
        if(node==nullptr)return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
public:
    LeftistHeap() : root(nullptr){}
    ~LeftistHeap() {clear(root);}
    //相当于合并
    void insert(int val){
        root=merge(root,new LeftistNode(val));
    }
    int deleteMin(){
        if(root==nullptr) throw std::runtime_error("heap is already empty");
        int minVal=root->key;
        LeftistNode* oldroot;
        root=merge(root->left,root->right);
        delete oldroot;
        return minVal;
    }
    //合并另外一棵树
    void merge(LeftistHeap& other){
        root=merge(root,other.root);
        other.root=nullptr;// 避免重复释放内存
    }
};

/*
插入与删除操作
插入：将新节点视为单节点树，与原树合并。

删除最小值：删除根节点后，合并左右子树。
*/