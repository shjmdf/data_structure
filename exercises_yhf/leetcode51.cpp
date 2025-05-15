#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<pair<int, int> >> ret;
        vector<vector<string>> solveNQueens(int n) {
            vector<pair<int, int> > blankpts;
            QueenAns(n,n,blankpts);
            vector<vector<string> > ans;
            for(auto poss:ret){
                vector<string> ans0(n);
                for(auto pos:poss){
                    string temp="";
                    for(int i=0;i<n;i++){
                        if(i!=pos.second-1)temp+='.';
                        else temp+='Q';
                    }
                    ans0[pos.first-1]=temp;
                }
                ans.push_back(ans0);
            }
            return ans;
        }
        //保证了不在同一行
        bool QueenContradict(const vector<pair<int,int> >& ans,const pair<int,int> Q2){
            for(const auto& Q1:ans){
                    if(Q2.second==Q1.second) return true;
                    if(abs(Q2.second-Q1.second)==abs(Q1.first-Q2.first))return true;
                }
            return false;
        }
        void QueenAns(int num,int row,vector<pair<int, int> >& ans){
            if(row==0){
                ret.push_back(ans);
                return;
            }
            for(int i=1;i<=num;i++){
                if(!QueenContradict(ans, make_pair(row, i))){
                    ans.push_back(make_pair(row,i));
                    QueenAns(num,row-1,ans);
                    ans.pop_back();
                }
            }
            return;
        }       
    };