#include<bits/stdc++.h>
typedef struct BiTree{
    char name;
    BiTree* lchild=nullptr;
    BiTree* rchild=nullptr;
    BiTree* parent=nullptr;
}Node;
using namespace std;
void preOrder(Node* node){
    if(node->name=='*')return;
    cout<<node->name;
    if(node->lchild!=nullptr)preOrder(node->lchild);
    if(node->rchild!=nullptr)preOrder(node->rchild);
}
void inOrder(Node* node){
    if(node->name=='*')return;
    if(node->lchild!=nullptr)inOrder(node->lchild);
    cout<<node->name;
    if(node->rchild!=nullptr)inOrder(node->rchild);
}
void PostOrder(Node* node){
    if(node->name=='*')return;
    if(node->lchild!=nullptr)PostOrder(node->lchild);
    if(node->rchild!=nullptr)PostOrder(node->rchild);
    cout<<node->name;
}
int main(){
    int n;   
    cin>>n; 
    for(int i=1;i<=n;i++){
        vector< pair<pair<char, int>,Node*>> s;
        Node* root=new Node();
        string temp_s;
        do{
            cin>>temp_s;
            if(temp_s=="0")break;
            int loc=0;
            while(temp_s[loc]=='-'){
                loc++;
            }
            s.push_back(make_pair(make_pair(temp_s[temp_s.length()-1],loc),new Node()));
        }while(true);
        s[0].second->name=s[0].first.first;
        for(int j=1;j<int(s.size());j++){
            int depth=s[j].first.second;
            char name=s[j].first.first;
            int fn;
            for(int k=j-1;k>=0;k--){
                if(s[k].first.second<depth){
                    fn=k;
                    break;
                }
            }
            if(s[fn].second->lchild==nullptr){
                s[fn].second->lchild=s[j].second;
                s[j].second->name=name;
                s[j].second->parent=s[fn].second;
            }
            else{
                s[fn].second->rchild=s[j].second;
                s[j].second->name=name;
                s[j].second->parent=s[fn].second;
            }
        }
        root=s[0].second;
        preOrder(root);
        cout<<endl;
        PostOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        cout<<endl;
    }
    return 0;
}