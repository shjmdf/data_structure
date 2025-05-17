//Question：如果数据在1000000范围，
//且插入成绩在long以内。
//那主席树必然得（？）离散化吧
//要再把map写成红黑树，pq写成堆我真写不动了orz
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000
struct Node{
    int l,r;
    int cnt;
    Node():l(0),r(0),cnt(0){};
};
//query
struct qry{
    int num;//顺序
    long l;
    long r;
    int k;
    qry(int n,long left,long right,int kth):num(n),l(left),r(right),k(kth){};
};
#define MAX 1000020
vector<pair<long, int> > nums;
priority_queue<long> pq;
vector<qry> querys;
Node tree[MAX];
int root[MAX];//version roots
int node_cnt;
int num_insert;//version control
map<long, int> maps;
vector<long> dis2val;
//可持久化(0-nums.size()-1,pos为离散化的位置）
void update(int pre_rootidx,int& currootidx,int l,int r,int pos){
    currootidx=++node_cnt;
    tree[currootidx].l=tree[pre_rootidx].l;
    tree[currootidx].r=tree[pre_rootidx].r;
    tree[currootidx].cnt=tree[pre_rootidx].cnt+1;
    if(l==r){
        return;
    }
    int mid=l+(r-l)/2;
    if(pos<=mid){
        update(tree[pre_rootidx].l,tree[currootidx].l,l,mid,pos);
    }
    else update(tree[pre_rootidx].r,tree[currootidx].r,mid+1,r,pos);
    return;
}
//取版本号，递归求ql-qr间的总值(离散化的ql,qr)
int sum(int versionidx,int l,int r,int ql,int qr){
    if(l>qr||r<ql){
        return 0;
    }
    if(ql<=l&&r<=qr){
        return tree[versionidx].cnt;
    }
    int mid=l+(r-l)/2;
    int ans=0;
    ans+=sum(tree[versionidx].l,l,mid,ql,qr);
    ans+=sum(tree[versionidx].r,mid+1,r,ql,qr);
    return ans;
}
//找第k小值
int kth_smallest(int versionidx,int l,int r,int kr){
    if(l==r){
        return l;
    }
    int mid=l+(r-l)/2;
    int lchild_cnt=tree[tree[versionidx].l].cnt;
    if(kr<=lchild_cnt){
        return kth_smallest(tree[versionidx].l,l,mid,kr);
    }
    else return kth_smallest(tree[versionidx].r,mid+1,r,kr-lchild_cnt);
}
int main(){
    int n;
    scanf("%d",&n);
    //输入+离散化
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp==0){
            long num;
            scanf("%ld",&num);
            nums.push_back(make_pair(num,i));
            pq.push(-num);
        }
        //压入查询
        else{
            long left,right;
            int kth;
            scanf("%ld%ld%d",&left,&right,&kth);
            querys.push_back(qry(i,left,right,kth));
            pq.push(-left);
            pq.push(-right);
        }
    }
    int tempcnt=0;
    long a=-1,b;
    //离散化，映射到数据（取消重复的数据）
    while(!pq.empty()){
        b=-pq.top();
        pq.pop();
        if(a!=b) {
            maps[b]=tempcnt++;
            dis2val.push_back(b);
        }
        a=b;
    }
    //伪在线
    int data_num=tempcnt;
    int treecnt=0,querycnt=0;
    int nums_size=nums.size(),querys_size=querys.size();
    for(int i=0;i<n;i++){
        if(treecnt==nums_size){
            while(querycnt!=querys_size){
                int last_root=root[num_insert];
                int countlessL=0;
                //离散化映射
                int l=maps[querys[querycnt].l];
                int k=querys[querycnt].k;
                if(l>0){
                    countlessL=sum(last_root,0,data_num-1,0,l-1);
                }
                k+=countlessL;
                //输出答案
                printf("%ld\n",dis2val[kth_smallest(last_root,0,data_num-1,k)]);
                querycnt++;
            }
            break;
        }
        if(querycnt==querys_size){
            while(treecnt!=nums_size){
                num_insert++;
                update(root[num_insert-1],root[num_insert],0,data_num-1,maps[nums[treecnt].first]);
                treecnt++;
            }
            break;
        }
        if(nums[treecnt].second<querys[querycnt].num){
            num_insert++;
            update(root[num_insert-1],root[num_insert],0,data_num-1,maps[nums[treecnt].first]);
            treecnt++;
            continue;
        }
        else{
            int last_root=root[num_insert];
            int countlessL=0;
            //离散化映射
            int l=maps[querys[querycnt].l];
            int k=querys[querycnt].k;
            if(l>0){
                countlessL=sum(last_root,0,data_num-1,0,l-1);
            }
            k+=countlessL;
            //输出答案
            printf("%ld\n",dis2val[kth_smallest(last_root,0,data_num-1,k)]);
            querycnt++;
        }
    }
    return 0;
}