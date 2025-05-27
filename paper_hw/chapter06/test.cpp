typedef struct{
    int key;
    int info;
}Node;
#define MAX 1000
typedef struct{
    Node e[MAX];
    int n;
}Seq;
int func(int key,Seq *seq){
    for(int i=0;i<seq->n;i++){
        if(seq->e[i].key==key){
            if(i){
                Node temp;
                temp=seq->e[i-1];
                seq->e[i-1]=seq->e[i];
                seq->e[i]=temp;
                return seq->e[i-1].info;
            }
            else {
                return seq->e[i].info;
            }
        }
    }
    return -1;
}