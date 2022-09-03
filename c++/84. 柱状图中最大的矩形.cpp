#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
class myqueue {
public:
    deque<pair<int, int>> que;
    void pop(int val) {
        while (!que.empty() && que.front().first == val) {
            que.pop_front();
        }
    }
    void push(int val) {
        while (!que.empty() && que.back().first >= val) {
            que.pop_back();
        }
    }
    pair<int, int> front() {
        return que.front();
    }
    pair<int, int> back() {
        return que.back();
    }
};
class Solution_84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        myqueue lq, rq;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        for (int i = 0; i < n; ++i) {
            lq.push(heights[i]);
            l[i] = lq.que.empty() ? -1 : lq.back().second;
            lq.que.push_back(make_pair(heights[i], i));
        }
        for (int j = n - 1; j >= 0; --j) {
            rq.push(heights[j]);
            r[j] = rq.que.empty() ? n : rq.back().second;
            rq.que.push_back(make_pair(heights[j], j));
        }
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            max_area = max(max_area, heights[i] * (r[i] - l[i] - 1));
        }
        return max_area;
    }
};
/*
class Solution_84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // int max_h= heights[max_element(heights.begin(),heights.end())-heights.begin()];
        int max_h = *max_element(heights.begin(), heights.end());
        //cout << max_h;
        vector<vector<int>> map(n, vector<int>(max_h, 0));
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            for (int j = 0; j < h; ++j) {
                j == 0 ? map[i][j] = 1 : map[i][j] = map[i][j - 1] + 1;
            }
        }
        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < max_h; ++j) {
                if (map[i][j] > 0) {
                    int max_w = map[i][j];
                    max_area = max(max_area, max_w);
                    // max_area = max_w;
                    int h = 1;
                    int k = i - 1;
                    while (k >= 0 && map[k][j] > 0) {
                        max_w = min(max_w, map[k][j]);
                        h++;
                        max_area = max(max_area, max_w * h);
                        k--;
                    }
                }
            }
        }
        return max_area;
    }
};
*/
void main_84() {
    Solution_84 s_84;
    vector<int> input;
    int num;
    while (cin >> num) {
        input.push_back(num);
        if (cin.get() == '\n') break;
    }
    cout<<s_84.largestRectangleArea(input);
}