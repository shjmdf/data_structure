#include<bits/stdc++.h>
struct dt{
    int pos;
    bool tp;
    dt(int p,bool t):pos(p),tp(t){};
};
using namespace std;
stack<dt> st;
int main(){
    int n;
    string str;
    while(cin>>n){
        cin>>str;
        int len=str.length();
        for(int i=0;i<len;i++){
            bool ty=bool(int(str[i]-'0')-1);
            dt temp=dt(i+1,ty);
            if(!ty){
                st.push(temp);
            }
            else{
                dt t=st.top();
                st.pop();
                cout<<t.pos;
                if(i!=len-1) cout<<" ";
            }
        }
        cout<<endl;
        while(!st.empty()){
            st.pop();
        }
    }
    return 0;
}