#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution_210 {
public:
    stack<int> ret;
    vector<int> vst;
    vector<int> result;
    vector<vector<int>> map;
    bool flag = true;
    void dfs(int i) {
        vst[i] = 1;
        for (auto& m : map[i]) {
            if (flag && vst[m] == 0) {
                dfs(m);
                // if(!flag){
                //     return;
                // }
            }
            else if (vst[m] == 1) {
                flag = false;
                return;
            }
        }
        vst[i] = 2;
        ret.push(i);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vst.resize(numCourses);
        map.resize(numCourses);
        for (auto& m : prerequisites) {
            map[m[1]].push_back(m[0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (vst[i] == 0 && flag) {
                dfs(i);
            }
        }
        while (ret.size() > 0) {
            result.push_back(ret.top());
            ret.pop();
        }
        if (!flag) return {};
        return result;
    }
};