#include<bits/stdc++.h>
using namespace std;
int n,k;
int d,x,y;
int fake;
typedef struct{
    int pnum=-1;//parentnum
    int cnum=-1;//which class to belong
    //pnum=cnum-1(always)
}Union;
vector< vector<int> > animals;
Union a[50001];
int main(){
    cin>>n>>k;
    int classnum=0;
    for(int i=1;i<=k;++i){
        cin>>d>>x>>y;
        if(x>n||y>n||(x==y&&d==2)){
            fake++;
        }
        if(d==0){
            if(a[x].cnum==-1&&a[y].cnum==-1){//目前都不知道

            }
        }
    }
    return 0;
}