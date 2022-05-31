#include<iostream>
#include<vector>
using namespace std;
class solution_673 {
	public:
		int findNumberOfLIS(vector<int>& nums) {
			int n = nums.size();
			vector<int> dp(n, 1);
			vector<int> cnt(n, 1);
			int ret = 0;
			int max_l = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j]) {
						if (dp[i] < dp[j] + 1) {
							dp[i] = dp[j] + 1;
							cnt[i] = cnt[j];
						}
						else if (dp[i] == dp[j] + 1) {
							cnt[i] += cnt[j] ;
						}
					}
				}
				if (dp[i] > max_l) {
					max_l = dp[i];
					ret = cnt[i];
				}
				else {
					if (dp[i] == max_l) {
						ret += cnt[i];
					}
				}
			}
			return ret;
	}
};
int main() {
	solution_673 s673;
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	cout<<s673.findNumberOfLIS(nums);
	return 0;
}