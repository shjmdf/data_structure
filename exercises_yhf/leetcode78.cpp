#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            ans.push_back(temp);
            for(const auto& numv:nums){
                subset(ans,numv);
            }
            return ans;
        }
        void subset(vector<vector<int>>& ans,int num){
            vector<vector<int> > ans_copy=ans;
            for(auto x:ans_copy){
                x.push_back(num);
                ans.push_back(x);
            }
            return;
        }
    };