#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution_718 {
	public:
		int findLength(vector<int>& nums1, vector<int>& nums2) {
			int m = nums1.size(), n = nums2.size();
			if (m == 0 || n == 0) return 0;
			vector<vector<int>> dp(m + 1, vector<int>(n + 1));
			int ret = 0;
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (nums1[i - 1] == nums2[j - 1]) {
						dp[i][j] = dp[i - 1][j - 1] + 1;
						ret = max(dp[i][j], ret);
					}
				}
			}
			return ret;
		}
};
void main_718() {
	vector<int> nums1;
	vector<int> nums2;
	int num;
	while (cin >> num) {
		nums1.push_back(num);
		if (cin.get() == '\n') break;
	}
	while (cin>>num){
		nums2.push_back(num);
		if (cin.get() == '\n') break;
	}
	Solution_718 s_718;
	cout<<s_718.findLength(nums1, nums2)<<endl;
}