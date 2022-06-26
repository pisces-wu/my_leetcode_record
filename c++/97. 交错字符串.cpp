#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution_97 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) return false;
        //¶þÎ¬dp
        //vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        //dp[0][0] = true;
        /*for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }*/
        //for (int i = 0; i <= m; ++i) {
        //    for (int j = 0; j <= n; ++j) {
        //        if (i > 0 ) {
        //            dp[i][j] = dp[i - 1][j]&&s1[i - 1] == s3[i + j - 1];
        //        }
        //        if (j > 0 ) {
        //            dp[i][j] |=  dp[i][j - 1]&&s2[j - 1] == s3[i + j - 1];
        //        }
        //    }
        //}
        //return dp[m][n];

        //Ò»Î¬dp
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i > 0) {
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0) {
                    dp[j] = dp[j] || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[n];
        
    }
};
void main_97() {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    Solution_97 s_97;
    if (s_97.isInterleave(s1, s2, s3)) {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}