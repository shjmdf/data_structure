#define MaxSize 100
struct SString{
    char ch[MaxSize+1];
    int length;
}a,b;
int next[MaxSize+1];
//KMP algorithm
int KMP(SString &a,SString &b,int pos){
    int i,j;
    i=pos,j=1;
    while(i<=a.length && j<=b.length){
        if(j==0 || a.ch[i]==b.ch[j]){
            i++;
            j++;
        }
        else j=next[j];
    }
    return -1;
}
void Next(SString &b){
    next[1]=0;
    int i=2,j=1;
    while(i<=b.length){
        if(b.ch[i]==b.ch[j]){
            next[i]=j;
            i++;
            j++;
        }
        else {
            if (j==1){
                next[i]=0;
                i++;
            }
            else j=next[j]+1;
        }
    }
}
//a b a a b a b
//0 0 1 1 2 3 2