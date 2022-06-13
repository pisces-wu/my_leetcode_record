#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution_712 {
	public:
		int minimumDeleteSum(string s1, string s2) {
			int m = s1.size(), n = s2.size();
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            for (int i = 1; i < n + 1; i++) {
                for (int j = 1; j < m + 1; j++) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                    }
                    else {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }
            int ascii_1 = 0, ascii_2 = 0;
            for (int i = 0; i < n; i++) ascii_1 += s1[i];
            for (int j = 0; j < m; j++) ascii_2 += s2[j];
            return (ascii_1 - dp[n][m]) + (ascii_2 - dp[n][m]);
		}
};
void main() {
    string s1, s2;
    cin >> s1 >> s2;
    Solution_712 s_712;
    cout<<s_712.minimumDeleteSum(s1, s2)<<endl;
}