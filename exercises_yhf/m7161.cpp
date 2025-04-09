#include<bits/stdc++.h>
using namespace std;
struct Node{
    int degree;
    char ch;
    vector<Node*> kid;
};
void lrd(Node* node){
    for(auto& k:node->kid){
        lrd(k);
    }
    cout<<node->ch<<" ";
}
int main(){
    int n;
    cin>>n;
    string s;
    cin.ignore();
    for(int num=1;num<=n;num++){        
        getline(cin,s);
        int len=s.length();
        int treelen=(len+1)/4;//树长
        vector<Node*> tree;
        for(int i=0;i<len;i+=4){
            Node* node=new Node();
            node->ch=s[i];
            node->degree=(int)s[i+2]-'0';
            tree.push_back(node);
        }

        int loc=0;
        for(int i=0;i<treelen;i++){
            loc=max(loc,i);
            int temp=tree[i]->degree;

            if(temp>0){//有子节点

                for(int j=1;j<=temp;j++){
                    tree[i]->kid.push_back(tree[loc+1]);
                    loc++;
                }
            }
        }
        /*
        for(auto& node:tree){
            cout<<node->ch<<' '<<node->degree;
            for(auto& k:node->kid){
                cout<<k->ch;
            }
            cout<<endl;
        }
        */
            
        lrd(tree[0]);
        for(auto node:tree) {
           delete node;
        }
    }
    return 0;
}