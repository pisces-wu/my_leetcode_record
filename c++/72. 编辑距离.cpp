#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution_72 {
	public:
		int minDistance(string word1, string word2) {
			int m = word1.size(), n = word2.size();
			if (m == 0) return n;
			if (n == 0) return m;
			vector<vector<int>> dp(m + 1, vector<int>(n + 1));
			for (int i = 1; i <= m; ++i) {
				dp[i][0] = dp[i - 1][0] + 1;
			}
			for (int j = 1; j <= n; ++j) {
				dp[0][j] = dp[0][j - 1] + 1;
			}
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (word1[i - 1] == word2[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
				}
			}
			return dp[m][n];
 		}

};
void main_72() {
	Solution_72 s72;
	string word1;
	string word2;
	cin >> word1;
	cin >> word2;
	cout<<s72.minDistance(word1, word2)<<endl;
	
}