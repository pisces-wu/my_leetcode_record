#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution_o45 {
public:
    string minNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> nnums;
        for (int i = 0; i < n; ++i) {
            nnums.push_back(to_string(nums[i]));
        }
        sort(nnums.begin(), nnums.end(), [](string& a, string& b) {
            return a + b < b + a;
            });
        string ret;
        for (int i = 0; i < nnums.size(); ++i) {
            ret += nnums[i];
        }
        return ret;
    }
};
void main_o45() {
    Solution_o45  s_o45;
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }
    string  ret=s_o45.minNumber(nums);
    cout << ret;
}