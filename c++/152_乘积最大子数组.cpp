#include<iostream>
#include<vector>
using namespace std;
class solution_152 {
	public:
		int	maxProduct(vector<int>& nums) {
			int n = nums.size();
			if (n <= 0) return n;
			if (n == 1) return nums[0];
			int max_pre = 1,min_pre = 1;
			int cur_max = 1, cur_min = 1;
			int ret = nums[0];
			for (int i = 0; i < n; ++i) {
				int tmp1 = cur_max, tmp2 = cur_min;
				cur_max = max(max(nums[i] * max_pre, nums[i] * min_pre),nums[i]);
				cur_min = min(min(nums[i] * max_pre, nums[i] * min_pre),nums[i]);
				max_pre = cur_max;
				min_pre = cur_min;
				ret = max(ret, cur_max);
			}
			return ret;
		}
};
int main_152() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	solution_152 s152;
	cout<<s152.maxProduct(nums);
	return 0;
}