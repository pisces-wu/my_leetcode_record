#include<iostream>
#include<vector>
using namespace std;
class Solution_463 {
public:
    vector<vector<int>> dir = { {-1,0},{1,0},{0,1},{0,-1} };
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k][0];
                        int y = j + dir[k][1];
                        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
                            ++ret;
                        }
                    }
                }
            }
        }
        return ret;
        // int max_l=0,max_h=0;
        // for(int i=0;i<m;++i){
        //     int w=0;
        //     for(int j=0;j<n;++j){
        //         if(grid[i][j]==1){
        //             ++w;
        //         }
        //     }
        //     max_l=max(w,max_l);
        // }
        // for(int j=0;j<n;++j){
        //     int h=0;
        //     for(int i=0;i<m;++i){
        //         if(grid[i][j]==1){
        //             ++h;
        //         }
        //     }
        //     max_h=max(max_h,h);
        // }
        // return 2*(max_l+max_h);
    }
};
int main_463() {

}
