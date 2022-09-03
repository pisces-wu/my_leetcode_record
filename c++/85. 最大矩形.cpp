#include<iostream>
#include<vector>
using namespace std;
class Solution_85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') grid[i][j] = j > 0 ? grid[i][j - 1] + 1 : 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    int w = grid[i][j];
                    int k = i - 1;
                    int h = 2;
                    int area = w;
                    while (k >= 0 && grid[k][j] != 0) {
                        w = min(w, grid[k--][j]);
                        area = max(area, w * h);
                        h++;
                    }
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }
};
void main_85() {
    Solution_85 s_85;
    int m, n;
    cin >> m >> n;
    vector<vector<char>> matrix(m,vector<char>(n,'0'));
    int num;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> num;
            matrix[i][j] = '0'+num;
        }
    }
    cout<<s_85.maximalRectangle(matrix);
}