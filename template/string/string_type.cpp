#define MaxSize 100
struct SString{
    char ch[MaxSize+1];
    int length;
};

//heap
struct HString{
    char *ch;
    int length;
};