typedef struct _ListNode{
    int data;
    struct _ListNode *next;
}ListNode;
typedef ListNode* Loop_llist;
Loop_llist Listinit(){
    Loop_llist list = new ListNode;
    list->next = list; // Initialize the next pointer to point to itself
    list->data=-1;
    return list;
}
void ListInsert(Loop_llist list,int data, int n){
    if (list->data==-1 || n<1)
        return;
    ListNode* current=list;
    for (int i=0;i<n-1 && current->next!=list;i++){
        current=current->next;
    }
    ListNode* dot=new ListNode;
    dot->data=data;
    dot->next=current->next;
    current->next=dot;
    return;
}
