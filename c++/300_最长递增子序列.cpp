#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

//dp动态规划 ac
class solution_300 {
public:
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return n;
		vector<int> dp(n, 1);
		int ret = INT_MIN;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ret = max(ret, dp[i]);
		}
		return ret;
	}
};
/*
class myqueue {
	public:
		deque<int> q;
		void pop(int val) {
			if (!q.empty() && q.front() == val) {
				q.pop_front();
			}
		}
		void push(int val) {
			while (!q.empty()&&q.back() < val) {
				q.pop_back();
			}
			q.push_back(val);
		}
		int front() {
			return q.front();
		}
};
*/

//单调队列 //有问题
/*
class solution_300 {
public:
	int lengthOfLIS(vector<int>& nums) {
		deque<int> que;
		int n = nums.size();
		if (n < 2) return n;
		int ret = INT_MIN;
		for (int i = 0; i < n; ++i) {
			if (que.empty()) {
				que.push_back(nums[i]);
				continue;
			}
			while (!que.empty() && que.back() > nums[i]) {
				que.pop_back();
			}
			que.push_back(nums[i]);
			ret = max(ret, (int)que.size());
		}
		return ret;
	}
};*/

int main_300() {
	solution_300 s_300;
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	cout << s_300.lengthOfLIS(nums);
	return 0;
}