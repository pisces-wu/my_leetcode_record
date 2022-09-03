#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class meituan_nihe {
public:
	int ansor(vector<int>& a, vector<int>& b) {
		int n = a.size();
		int m = b.size();
		//int k = min(m, n);
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
		for (int i = 1; i <= n; ++i) {
			dp[i][0] = dp[i - 1][0] + abs(a[i-1]);
		}
		for (int j = 1; j <= m; ++j) {
			dp[0][j] = dp[0][j - 1] + abs(b[j-1]);
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (a[i - 1] == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if(a[i - 1] != b[j- 1])
				{
					dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i-1] - b[j-1]), min(dp[i - 1][j] + abs(a[i - 1]), dp[i][j - 1] + abs(b[j - 1])));
				}
			}
		}
		return dp[n][m];
	}
};
void main_m() {
	int num, m, n;
	vector<int> a;
	vector<int> b;
	cin >> n >> m;
	while (n--) {
		cin >> num;
		a.push_back(num);
	}
	while (m--) {
		cin >> num;
		b.push_back(num);
	}
	meituan_nihe s_nihe;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	cout << s_nihe.ansor(a, b);
}