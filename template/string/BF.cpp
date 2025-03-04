#define MaxSize 100
struct SString{
    char ch[MaxSize+1];
    int length;
}a,b;
//Brute_Force algorithm
int BF(SString &a,SString &b,int pos){
    if (a.length<b.length) return -1;
    int i=pos,j=1;
    while(i+b.length<=a.length){
        if(a.ch[i]==b.ch[j]){
            i++;
            j++;
            if(j>b.length) return i-b.length;
        }
        else{
            i=i-j+2;
            j=1;
        }
    }
    return -1;
}