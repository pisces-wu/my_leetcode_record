#include<iostream>
#include<vector>
using namespace std;
class solution_53 {
	public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return n;
		if (n == 1) return nums[0];
		vector<int> dp(n, 0);
		dp[0] = max(0, nums[0]);
		int ret = INT_MIN;
		for (int i = 1; i < n; ++i) {
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};
int main_53() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	solution_53 s53;
	cout<<s53.maxSubArray(nums);
	return 0;
}