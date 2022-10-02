#include<iostream>
#include<vector>
using namespace std;
class Solution_169 {
public:
	int solve(vector<int>& nums) {
		if (nums.size() <= 0) return -1;
		int major_num = nums[0];
		int ret = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == major_num) {
				++ret;
			}
			else {
				--ret;
				if (ret == 0) {
					major_num = nums[i];
					ret = 1;
				}
			}
		}
		return major_num;
	}
};
void main_169() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	Solution_169 s_169;
	cout << s_169.solve(nums) << endl;
}