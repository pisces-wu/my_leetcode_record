#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution_115 {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m == 0 || n == 0) return 0;
        //  vector<vector<int>> dp(m+1,vector<int>(n+1));
        //  for(int i=0;i<=m;++i) {
        //      dp[i][0]=1;
        //  }
        //  for(int i=1;i<=m;++i){
        //      for(int j=1;j<=n;++j){
        //          if(INT_MAX-dp[i-1][j]>=dp[i-1][j-1]&&s[i-1]==t[j-1]){
        //              dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        //          }
        //          else{
        //              dp[i][j]=dp[i-1][j];
        //          }
        //      }
        //  }
        //  return dp[m][n];
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = n; j >= 1; --j) {
                if (INT_MAX - dp[j] >= dp[j - 1] && s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};
void main_115() {
    string s, t;
    cin >> s;
    cin >> t;
    Solution_115 s_115;
    cout<<s_115.numDistinct(s, t)<<endl;
}