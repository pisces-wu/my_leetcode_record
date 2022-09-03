#include<iostream>
#include<vector>
using namespace std;
class Solution_77 {
public:
    vector<vector<int>> ret;
    vector<int> path;
    void show_ret() {
        for (auto& v:ret){
            for (auto& num : v) {
                cout << num << "  ";
            }
            cout << endl;
        }

    }
    void backtracking(int start_index, int n, int k) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        for (int i = start_index; i <= n + 1 - (k - path.size()); i++) {
            path.push_back(i);
            backtracking(i + 1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return ret;
    }
};
void main_77() {
    Solution_77 s_77;
    s_77.combine(4, 2);
    s_77.show_ret();
}