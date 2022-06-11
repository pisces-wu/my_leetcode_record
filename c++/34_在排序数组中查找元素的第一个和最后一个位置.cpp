#include<iostream>
#include<vector>
using namespace std;
class Solution_34 {
	public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		int l = 0, r = n - 1;
		int k=-1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (nums[mid] == target) {
				k = mid; break;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			else
			{
				l = mid - 1;
			}
		}
		if (k != -1) {
			int ll=k, rr=k;
			while (ll - 1 >= 0 && nums[ll - 1] == nums[ll]) {
				--ll;
			}
			while (rr + 1 < n && nums[rr] == nums[rr + 1]) {
				++rr;
			}
			return { ll,rr };
		}
		return{ -1,-1 };
	}
};
void main_34() {
	int num;
	vector<int> nums;
	int target;
	cout << "请输入一个数组:" << endl;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	cout << "请输入要查找的数：" << endl;
	cin >> target;
	Solution_34 s34;
	vector<int> ret(s34.searchRange(nums, target));
	cout << "查找结果区间为：" << endl;
	cout << "[" << ret[0] << "," << ret[1] << "]" << endl;
	//ret=s34.searchRange(nums, target);
}