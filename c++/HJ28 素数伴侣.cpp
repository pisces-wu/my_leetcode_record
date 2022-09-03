#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include<iostream>
using namespace std;
//³¬Ê±
class solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void bt(vector<int>& nums, int start_index, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start_index; i < nums.size(); ++i) {
            if (used[i] == false) {
                path.push_back(nums[i]);
                used[i] = true;
                bt(nums, 0, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    void print() {
        int m = res.size();
        //cout << m;
        int n = res[0].size();
        //cout << n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
};
bool isvalue(int a, int b) {
    int num = a + b;
    if (num <= 1) return true;
    for (int i = 2; i < sqrt(num)+1; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}
void main_sushu() {
    int n;
    cin >> n;
    vector<int> nums;
    int num;
    while (n--) {
        cin >> num;
        nums.push_back(num);
        //if (cin.get() == '\n') break;
    }
    vector<bool> used(nums.size(), false);
    solution s;
    s.bt(nums, 0, used);
    //s.print();
    vector<vector<int>> ret(s.res);
    int k = ret.size();
    //cout << endl;
    //cout << "k" << k;
    int result = 0;
    for (int i = 0; i < k; ++i) {
        vector<int> one(ret[i]);
        int sub_ret = 0;
        for (int i = 0; i < one.size() - 1;) {
            int a = one[i];
            int b = one[i + 1];
            //cout << a << "  " << "b" << "  ";
            if (isvalue(a, b)) {
                sub_ret += 1;
            }
            i += 2;
        }
        result = max(result, sub_ret);
        //cout << endl;
    }
    cout << result << endl;
};