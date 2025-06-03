#include<bits/stdc++.h>
using namespace std;
int temp[100010];
int a[100010];
long long ans;
void merge(int l, int r);
void MergeAndCount(int l,int r);
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        temp[i]=a[i];
    }
    merge(1,n);
    cout<<ans;
    return 0;
}
void MergeAndCount(int l,int r){
    int mid=l+(r-l)/2;
    int i=l,j=mid+1;
    int loc=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            temp[loc++]=a[i++];
        }
        else{
            ans+=mid-i+1;
            temp[loc++]=a[j++];
        }
    }
    while(i<=mid){
        temp[loc++]=a[i++];
    }
    while(j<=r){
        temp[loc++]=a[j++];
    }
    for(int i=l;i<=r;i++){
        a[i]=temp[i];
    }
    return;
}
void merge(int l,int r){
    int mid=l+(r-l)/2;
    if(l<r){
        merge(l,mid);
        merge(mid+1,r);
        MergeAndCount(l,r);
    }
    return;
}
