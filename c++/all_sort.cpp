#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
using namespace std;
class all_sort {
public:
	void bubble_sort(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; ++i) {
			for (int j = 0; j < nums.size() - 1 - i; ++j) {
				if (nums[j] > nums[j + 1]) {
					swap(nums[j + 1], nums[j]);
				}
			}
		}
	}
	void select_sort(vector<int>& nums) {
		/*for (int i = 0; i < nums.size(); ++i) {
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[i] > nums[j]) {
					swap(nums[i], nums[j]);
				}
			}
		}*/
		for (int i = 0; i < nums.size(); ++i) {
			int max_index = i;
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[max_index] < nums[j]) {
					max_index = j;
				}
			}
			swap(nums[i], nums[max_index]);
		}
	}
	int quick_sort(vector<int>& nums, int l, int r) {
		int i = l - 1;
		int pivot = nums[r];
		for (int j = l; j < r; ++j) {
			if (nums[j] <= pivot) {
				i += 1;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[r], nums[i + 1]);
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
};
void main_sort() {
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (cin.get() == '\n') break;
	}
	all_sort sort;
	//sort.bubble_sort(nums);
	//sort.select_sort(nums);
	sort.random_quicksort(nums, 0, nums.size() - 1);
	for (auto m : nums) {
		cout << m << " ";
	}

}