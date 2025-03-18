#include<bits/stdc++.h>
using namespace std;
vector<int>lst;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int x;
        cin>>s;
        if(s=="add"){
            cin>>x;
            lst.push_back(x);
            continue;
        }
        if(s=="del"){
            lst.erase(lst.begin());
            continue;
        }
        if(s=="query"){
            vector<int> sorted=lst;
            sort(sorted.begin(),sorted.end());
            int size = sorted.size();
            if (size % 2 == 1) {
                cout << sorted[size / 2] << endl;
            } else {
                int mid1 = sorted[size / 2 - 1];
                int mid2 = sorted[size / 2];
                
                if ((mid1 + mid2) % 2 == 0) {
                    cout << (mid1 + mid2) / 2 << endl;
                } else {
                    cout << (mid1 + mid2) / 2.0 << endl;
                }
            }
            continue;
        }
    }
    return 0;
}