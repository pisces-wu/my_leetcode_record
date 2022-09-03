#include<iostream>
#include<vector>
using namespace std;
class Solution_33 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (target >= nums[0] && nums[mid] >= target) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && nums[n - 1] >= target) {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }            
        }
        return -1;
    }
};

void main_33() {
    vector<int> nums={ 4,5,6,7,0,1,2 };
    int target = 7;
    Solution_33 s_33;
    cout<<s_33.search(nums, target);
}