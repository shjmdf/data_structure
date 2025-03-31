#include<bits/stdc++.h>
template <class K,class E>
struct skipNode{
    typedef pair<const K,E> pairType;
    pairType element;
    skipNode<K,E> **next;
    skipNode(const pairType&  thePair, int size)
        :element(thePair){
            next=new skipNode<K,E>* [size+1];
        }
};
template <class K,class E>
struct skipList{
    float cutoff;//层数
    int levels;//最大的非空链表
    int dSize;
    int maxLevel;//最大链表层数
    int tailKey;//最大关键字
    skipNode<K,E>* headerNode;
    skipNode<K,E>* tailNode;
    skipNode<K,E>** last;//last[i]表示i层的最后节点
    skipList(K largeKey, int maxPairs, float prob);
};
template <class K,class E>
skipList<K,E> :: skipList(K largeKey, int maxPairs, float prob){
    //关键字小于largeKey, 数对个数最多为maxPairs
    cutoff=prob* RAND_MAX;
    maxLevel=(int)ceil(logf((float) maxPairs)/ logf(1/prob))-1;
    levels=0;
    dSize=0;
    tailKey=largeKey;

    //生成头节点，尾节点和数组last
    pair<K,E> tailPair;
    tailPair.first=tailKey;
    headerNode=new skipNode<K,E> (tailPair,maxLevel+1);
    tailNode=new skipNode<K,E> (tailPair,0);
    last=new skipNode<K,E> *[maxLevel+1];

    for(int i=0;i<=maxLevel;i++)
        headerNode->next[i]=tailNode;
}
