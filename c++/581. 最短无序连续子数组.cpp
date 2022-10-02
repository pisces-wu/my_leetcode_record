#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution_581 {
public:
    /*int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res(nums);
        sort(res.begin(), res.end());
        int l = 0, r = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != res[i]) {
                l = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] != res[i]) {
                r = i;
                break;
            }
        }
        return l == r ? 0 : r - l + 1;
    }*/
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = -1;
        int max_num = nums[0], min_num = nums[n - 1];
        for (int i = 0; i < n; ++i) {
            if (nums[i] < max_num) {
                r = i;
                }
            else {
                max_num = nums[i];
            }
            if (nums[n - 1 - i] > min_num) {
                l = n - 1 - i;
            }
            else {
                min_num = nums[n - 1 - i];
            }
        }
        return r - l + 1;
    }
};
int main_581() {
    vector<int> nums = { 2,6,4,8,10,9,15 };
    Solution_581 s_581;
    cout << s_581.findUnsortedSubarray(nums);
    return 0;
}