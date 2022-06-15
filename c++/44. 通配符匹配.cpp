#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution_44 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        if (m == 0 && n == 0) return true;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else break;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

void main_44() {
    string s, p;
    cin >> s;
    cin >> p;
    Solution_44 s_44;
    if (s_44.isMatch(s, p)) {
        cout << "true"<<endl;
    }
    else
    {
        cout << "false" << endl;
    }
}