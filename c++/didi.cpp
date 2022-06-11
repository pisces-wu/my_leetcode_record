#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool solve(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return true;
    int up = min(nums[0], nums[1]);
    int dw = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        if (nums[i] > up) {
            up = nums[i];
        }
        else if (nums[i] < dw) {
            dw = nums[i];
        }
        else return false;
    }
    return true;
}
int main_didi() {
    int n;
    cin >> n;
    vector<string> ret;
    while (n--) {
        int m;
        cin >> m;
        int num;
        vector<int> nums;
        while (m--) {
            cin >> num;
            nums.push_back(num);
        }
        if (solve(nums)) {
            ret.push_back("Yes");
            //cout << "Yes" << endl;
        }
        else {
            ret.push_back("No");
            //cout << "No" << endl;
        }
    }
    for (auto s : ret) {
        cout << s << endl;
    }
    return 0;
}