#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution_10_09 {
public:
	/*
	// Z型查找
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		if (m == 0) return false;
		int i = m-1, j = 0;
		while (i >= 0 && j < n) {
			if (matrix[i][j] > target) {
				--i;
			}
			else if (matrix[i][j] < target) {
				++j;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
	*/
	/*
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.empty() || matrix[0].empty()) return false;
		int rows = matrix.size() - 1, cols = matrix[0].size() - 1;
		int row = 0;
		while (row <= rows) {
			auto p = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
			if (p <= cols && matrix[row][p] == target) {
				return true;
			}
			++row;
		}
		return false;
	}*/
	//二分查找
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (const auto& row : matrix) {
			auto it = lower_bound(row.begin(), row.end(), target);
			if (it != row.end() && *it == target) {
				return true;
			}
		}
		return false;
	}
};
void main_10_09() {
	vector<vector<int>> grid;
	int rows = 0;
	int cols = 0;
	cout << "请输入行数和列数" << endl;
	cin >> rows >> cols;
	while (rows--) {
		int j = 0;
		int num;
		vector<int> nums;
		while (j++ < cols) {
			cin >> num;
			nums.push_back(num);
		}
		grid.push_back(nums);
	}
	int target;
	cout << "请输入要查找的数:" << endl;
	cin >> target;
	Solution_10_09 s10_09;
	if (s10_09.searchMatrix(grid, target)) {
		cout << "true" << endl;
	}
	else cout << "false" << endl;
}