#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
    int n,num;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num;
        vector<int> day(num+2);
        for(int j=1;j<=num;j++){
            cin>>day[j];
        }

        int sell2=0,sell1=0;
        int buy1=-day[1];
        int buy2=-day[1];

        for(int j=2;j<=num;j++){
            sell2=max(sell2,buy2+day[j]);
            buy2=max(buy2,sell1-day[j]);
            sell1=max(sell1,buy1+day[j]);
            buy1=max(buy1,-day[j]);
        }
        if(i!=n)cout<<sell2<<endl;
        else cout<<sell2;
    }
    return 0;
}