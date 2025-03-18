#include <bits/stdc++.h>
using namespace std;

bool canMatch(string s) {
    int n = s.length();
    
    // valid[i] = 长度为i的前缀是否有效
    vector<bool> valid(n+1, false);
    valid[0] = true;  // 空串为有效序列
    
    for (int i = 0; i < n; i++) {  // 当前位置
        for (int j = i; j >= 0; j--) {  // 子串起始位置
            int len = i - j + 1;  // 子串长度
            
            // 基本情况: 标准括号对
            if (len == 2 && 
                ((s[j]=='(' && s[i]==')') || 
                 (s[j]=='[' && s[i]==']') || 
                 (s[j]=='{' && s[i]=='}'))) {
                if (valid[j]) {  // 检查j之前的子串
                    valid[i+1] = true;
                    break;
                }
            }
            
            // 特殊规则: (()、[[]]、{{}}
            if (len == 3 && j+2 == i &&
                ((s[j]=='(' && s[j+1]=='(' && s[i]==')') || 
                 (s[j]=='[' && s[j+1]=='[' && s[i]==']') || 
                 (s[j]=='{' && s[j+1]=='{' && s[i]=='}'))) {
                if (valid[j]) {
                    valid[i+1] = true;
                    break;
                }
            }
            
            // 嵌套规则: (...)、[...]、{...}
            if (len > 2 && 
                ((s[j]=='(' && s[i]==')') || 
                 (s[j]=='[' && s[i]==']') || 
                 (s[j]=='{' && s[i]=='}'))) {
                if (valid[j] && valid[i] - valid[j+1]) {
                    valid[i+1] = true;
                    break;
                }
            }
            
            // 连接规则: S1S2
            if (valid[j] && j > 0 && valid[i+1-j]) {
                valid[i+1] = true;
                break;
            }
        }
    }
    
    return valid[n];
}


int main() {
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s += c;
    }
    
    cout << (canMatch(s) ? 1 : 0) << endl;
    return 0;
}

bool match(string s,int n){
    if (n==0){
        return false;
    }
    vector<bool> legal_ss(n+1,false);// legal_ss[i] for whether substring from 0 to i-1 is legal.
    legal_ss[0]=true;// NULL is true.
    for(int i=0;i<n;i++){//i for the end index of the substring
        for(int j=i;j>=0;i--){//j for the starting point,from the back (small to big)
            int len=i-j+1;
            if (len==2){
                if((s[j]=='(' && s[i]==')') || (s[j]=='[' && s[i]==']') || (s[j]=='{' && s[i]=='}')){
                    if(legal_ss[j]){//add a tail(actually a substring with len 2 also can be checked)
                        legal_ss[i+1]=true;
                        break;
                    }
                }
            
            }
        }
    }
}