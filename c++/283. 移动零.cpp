#include<iostream>
#include<vector>
using namespace std;
class Solution_283 {
public:
	vector<int> res;
	void solve(vector<int>& nums) {
		if (nums.size() <= 0) return;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0) {
				swap(nums[i], nums[j++]);
			}
		}
	}
};
int main_283() {
	int num;
	vector<int> ret;
	while (cin >> num) {
		ret.push_back(num);
		if (cin.get() == '\n') break;
	}
	Solution_283 s_283;
	s_283.solve(ret);
	for (auto m : ret) {
		cout << m << " ";
	}
	return 0;
}