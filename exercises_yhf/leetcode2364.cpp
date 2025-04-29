#include<bits/stdc++.h>
using namespace std;
int main(){

    return 0;
}
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            vector<int> copys=nums;
            int len=int(copys.size());
            unordered_map<int,int> maps;
            long long ans=0;
            for(int i=0;i<copys.size();i++){
                copys[i]-=i;
                ans+=i-maps[copys[i]];
                maps[copys[i]]++;
            }
            return ans;
        }
    };