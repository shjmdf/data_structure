#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        Solution(){
            InitMaps(maps);
        }
        vector<string> letterCombinations(string digits) {
            
            vector<string> ans;
            if(digits=="")return ans;
            ans.push_back("");
            int len=int(digits.length());
            for(int i=0;i<len;i++){
                vector<string> temp=ans;
                ans.clear();
                for(auto chr: maps[int(digits[i]-'0')]){
                    for(auto str:temp){
                        ans.push_back(str+chr);
                    }
                }
            }
            return ans;
        }
    private:
        map<int, vector<char>> maps;
        void InitMaps(map<int, vector<char>>& maps){
            maps.insert(make_pair(2,vector<char>{'a','b','c'}));
            maps.insert(make_pair(3,vector<char>{'d','e','f'}));
            maps.insert(make_pair(4,vector<char>{'g','h','i'}));
            maps.insert(make_pair(5,vector<char>{'j','k','l'}));
            maps.insert(make_pair(6,vector<char>{'m','n','o'}));
            maps.insert(make_pair(7,vector<char>{'p','q','r','s'}));
            maps.insert(make_pair(8,vector<char>{'t','u','v'}));
            maps.insert(make_pair(9,vector<char>{'w','x','y','z'}));
        }
        
    };