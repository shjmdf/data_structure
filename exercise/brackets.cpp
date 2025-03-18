#include <bits/stdc++.h>
using namespace std;
//use dp[i][j] to show whether it's a legal substring
//index: from i to j
int main() {
    int n;
    cin >> n;
    string s;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        s += c;
    }
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // cope with the 2
    for (int i = 0; i <= n-2; ++i) {
        int j = i + 1;
        if ((s[i] == '(' && s[j] == ')') ||(s[i] == '[' && s[j] == ']') ||(s[i] == '{' && s[j] == '}')) {
            dp[i][j] = true;
        }
    }
    //cope with the 3
    if (n >= 3) {
        for (int i = 0; i <= n-3; ++i) {
            int j = i + 2;
            if ((s[i] == '(' && s[i+1] == '(' && s[j] == ')') ||(s[i] == '[' && s[i+1] == '[' && s[j] == ']') ||(s[i] == '{' && s[i+1] == '{' && s[j] == '}')) {
                dp[i][j] = true;
            }
        }
    }
    
    //longer ~
    for (int l = 4; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            
            for (int k = i; k < j; ++k) {
                if (dp[i][k] && dp[k+1][j]) {
                    dp[i][j] = true;
                    break;
                }
            }
            if (dp[i][j]) continue;
            
            //3
            if ((s[i] == '(' && s[j] == ')') ||
                (s[i] == '[' && s[j] == ']') ||
                (s[i] == '{' && s[j] == '}')) {
                
                
                if (dp[i+1][j-1]) {
                    dp[i][j] = true;
                } else {
                    
                    if (s[i] == s[i+1]) {
                        int new_i = i + 2;
                        int new_j = j - 1;
                        if (new_i <= new_j) {
                            if (dp[new_i][new_j]) {
                                dp[i][j] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << (dp[0][n-1] ? 1 : 0) << endl;
    return 0;
}