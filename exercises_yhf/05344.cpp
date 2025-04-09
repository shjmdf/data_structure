#include<bits/stdc++.h>
using namespace std;
typedef struct DulNode{
    int data;//alive
    DulNode* previous;
    DulNode* next;
}DulNode,*DuLinkList;
int main(){
    int n,k;
    cin>>n>>k;
    DuLinkList start=new DulNode();
    start->data=1;
    DulNode* temp=start;
    for(int i=1;i<n;i++){
        DulNode* Node=new DulNode();
        Node->data=i+1;
        Node->previous=temp;
        temp->next=Node;
        temp=temp->next;
    }
    start->previous=temp;
    temp->next=start;
    temp=start;
    DulNode* toDelete;
    while(temp->next!=temp){
        for(int i=1;i<k;i++){
            temp=temp->next;
        }
        cout<<temp->data<<" ";
        toDelete=temp;
        temp=temp->next;
        toDelete->previous->next=toDelete->next;
        toDelete->next->previous=toDelete->previous;
        delete toDelete;
    }
    return 0;
}