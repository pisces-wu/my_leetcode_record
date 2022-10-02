#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;
//øÏ≈≈
class Solution_912 {
public:
	int quick_sort(vector<int>& nums, int l, int r) {
		int i = l - 1;
		int pivot = nums[r];
		for (int j = l; j < r; ++j) {
			if (nums[j] <= pivot) {
				++i;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[r]);
		return i + 1;
	}
	int random_partition(vector<int>& nums, int l, int r) {
		int i = rand() % (r - l + 1) + l;
		swap(nums[i], nums[r]);
		return quick_sort(nums, l, r);
	}
	void random_quicksort(vector<int>& nums, int l, int r) {
		if (l < r) {
			int pos = random_partition(nums, l, r);
			random_quicksort(nums, l, pos - 1);
			random_quicksort(nums, pos + 1, r);
		}
	}

	//πÈ≤¢≈≈–Ú
	void merge_sort(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		int mid = (l + r) >> 1;
		merge_sort(nums, l, mid);
		merge_sort(nums, mid + 1, r);
		int n = r - l + 1;
		//int tmp[n];
		vector<int> tmp(n, 0);
		for (int k = l; k <= r; ++k) {
			tmp[k - l] = nums[k];
		}
		int i = 0, j = mid - l + 1;
		for (int k = l; k <= r; ++k) {
			if (i == mid - l + 1 ) {
				nums[k] = tmp[j++];
			}
			else if (j == r - l + 1 || tmp[i] <= tmp[j]) {
				nums[k] = tmp[i++];
			}
			else nums[k] = nums[j++];
		}

	}
};

void main_912() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	Solution_912 s_912;
	//s_912.random_quicksort(nums, 0, nums.size() - 1);
	s_912.merge_sort(nums, 0, nums.size() - 1);
	for (auto m : nums) {
		cout << m << " ";
	}
}