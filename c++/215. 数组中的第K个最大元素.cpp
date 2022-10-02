#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution_215 {
public:
    //大顶堆 最优
    int findKthLargest(vector<int>& nums, int k) {
       priority_queue<int,vector<int>,greater<int>> que;
         for(int i=0;i<nums.size();++i){
            que.push(nums[i]);
            if(que.size()>k){
                que.pop();
            }
        }
        return que.top();
    }

    // k次选择排序
    // int findKthLargest(vector<int>& nums, int k) {
    //     for(int i=0;i<k;++i){
    //         for(int j=i+1;j<nums.size();++j){
    //             if(nums[i]<nums[j]){
    //                 swap(nums[i],nums[j]);
    //             }
    //         }
    //     }
    //     return nums[k-1];
    // }
    // 小改进
    /*int findKthLargest(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            int max_index = i;
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[max_index] < nums[j]) {
                    max_index = j;
                }
            }
            swap(nums[i], nums[max_index]);
        }
        return nums[k - 1];
    }*/
    /*int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < nums.size(); ++i) {
            que.push(nums[i]);
            if (que.size() > k) {
                que.pop();
            }
        }
        return que.top();
    }*/
};
void main_215() {
    vector<int> nums;
    int num;
    int k;
    cin >> k;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }
    Solution_215 s_215;
    cout<<s_215.findKthLargest(nums,k);
}