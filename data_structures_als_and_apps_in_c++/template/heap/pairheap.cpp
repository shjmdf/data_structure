#include<iostream>
using std::swap;
/*
本程序为配对堆
配对堆是一个支持插入，查询/删除最小值，合并，修改元素等操作的数据结构，
是一种可并堆。有速度快和结构简单的优势，
但由于其为基于势能分析的均摊复杂度，无法可持久化。

配对堆：小根堆+带权+多叉树
用son-sibling表示法存储

*/
template<class T>
struct Node {
    T v;
    Node *child=nullptr,*sibling=nullptr;
};
/*
和其他常见的堆结构相比，配对堆不维护任何额外的树大小，深度，排名等信息,
（二叉堆也不维护额外信息，但它是通过维持一个严格的完全二叉树结构来保证操作的复杂度）,
且任何一个满足堆性质的树都是一个合法的配对堆，
这样简单又高度灵活的数据结构
奠定了配对堆在实践中优秀效率的基础；
*/

//合并
//两个根节点较小的一个为新的根节点，
//然后将较大的根节点作为它的儿子插入进去。
template<class T>
Node<T>* meld(Node<T>* x,Node<T>* y){
    if(x==nullptr) return y;
    if(y==nullptr) return x;
    if(x->v>y->v) std::swap(x,y);
    y->sibling=x->child;
    x->child=y;
    return x;
}
//插入
//视作同理
template<class T>
Node<T>* insert(Node<T>* heap,Node<T>* y){
    if(heap==nullptr) return y;
    y->sibling=heap->child;
    heap->child=y;
    return heap;
}
/*
上文的几个操作都十分偷懒，完全没有对数据结构进行维护，
所以我们需要小心设计删除最小值的操作，来保证总复杂度不出问题。
去掉根节点后，哦嚯，变成森林了
但是如果完全合并所有的儿子，那就变成消愁了O(n)
所以需要以下两步走：
1.儿子们两两配对，两两meld
2. 从右到左合并新堆，老儿子先合并(长子继承法)

*/
//merges用来合并x的所有兄弟
template<class T>
Node<T>* merges(Node<T>* x){
    if(x==nullptr || x->sibling==nullptr) return x;
    Node<T>* y=x->sibling;
    Node<T>* c=y->sibling;
    x->sibling=y->sibling=nullptr;
    return meld(merges(c),meld(x,y));
    //后面递归合并，所以c先完成，再合并x,y,达成先老儿子的效果
}
//此时删掉最小值，也就是根节点，就显然了，把他的儿子们都合并
template<class T>
Node<T>* delete_min(Node<T>* x){
    Node<T>* t=merges(x->child);
    delete x;
    return t;
}
/*
减小一个元素的值
要实现这个操作，需要给节点添加一个「父」指针，
当节点有左兄弟时，其指向左兄弟而非实际的父节点；
否则，指向其父节点。
*/
//做修改
struct Node_2nd {
    long long v;
    int id;
    Node_2nd* child=nullptr;
    Node_2nd* sibling=nullptr;
    Node_2nd* father=nullptr;
};

Node_2nd* meld_2nd(Node_2nd* x,Node_2nd* y){
    if(x==nullptr) return y;
    if(y==nullptr) return x;
    if(x->v>y->v) std::swap(x,y);
    if(x->child!=nullptr){//做父指针维护
        x->child->father=y;
    }
    y->sibling=x->child;
    y->father=x;
    x->child=y;
    return x;
}
Node_2nd* merges_2nd(Node_2nd* x){
    if(x==nullptr) return nullptr;
    x->father=nullptr;
    if(x->sibling==nullptr) return x;
    Node_2nd* y=x->sibling;
    y->father=nullptr;
    Node_2nd* c=y->sibling;
    x->sibling=y->sibling=nullptr;
    return meld_2nd(merges_2nd(c),meld_2nd(x,y));
}
Node_2nd* decrease_key(Node_2nd* root,Node_2nd* x, long long v){
    x->v=v;
    if(x==root)return x;
    if(x->father->child==x){
        x->father->child=x->sibling;
    } else{
        x->father->sibling=x->sibling;
    }
    if(x->sibling!=nullptr){
        x->sibling->father=x->father;
    }
    x->sibling=nullptr;
    x->father=nullptr;
    return meld_2nd(x,root);
}
/*
配对堆结构与实现简单，但时间复杂度分析并不容易。

原论文1仅将复杂度分析到 meld 和 delete-min 操作均为均摊 O(\log n)，
但提出猜想认为其各操作都有和斐波那契堆相同的复杂度。

遗憾的是，后续发现，不维护额外信息的配对堆，
在特定的操作序列下，decrease-key 操作的均摊复杂度下界至少为 \Omega (\log \log n)2。

目前对复杂度上界比较好的估计有，Iacono 的 O(1) meld，O(\log n) decrease-key3；
Pettie 的 O(2^{2 \sqrt{\log \log n}}) meld 和 decrease-key4。
需要注意的是，前述复杂度均为均摊复杂度，因此不能对各结果分别取最小值。
*/