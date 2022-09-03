#include<iostream>
#include<vector>
using namespace std;
class Solution_200 {
public:
    // bool dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vst,vector<vector<int>>& map){
    //     int m=grid.size(),n=grid[0].size();
    //     if(i<0||i>=grid.size()||j<0||j>grid[0].size()){
    //       return 1; 
    //     }
    //     if(vst[i][j]!=-1) return map[i][j];
    //     vst[i][j]=1;
    //     if(grid[i][j]=='0') {map[i][j]=1;return 1;}
    //     map[i][j]=dfs(i+1,j,grid,vst,map)&&dfs(i-1,j,grid,vst,map)&&dfs(i,j+1,grid,vst)&&dfs(i,j-1,grid,vst,map);
    //     //vst[i][j]=dfs(i+1,j,grid,vst)&&dfs(i,j+1,grid,vst);
    //     return map[i][j];
    // }
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        grid[i][j] = '0';
        if (i >= 1 && grid[i - 1][j] == '1') dfs(i - 1, j, grid);
        if (i < m - 1 && grid[i + 1][j] == '1') dfs(i + 1, j, grid);
        if (j >= 1 && grid[i][j - 1] == '1') dfs(i, j - 1, grid);
        if (j < n - 1 && grid[i][j + 1] == '1') dfs(i, j + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0) return 0;
        // vector<vector<int>> vst(m,vector<int>(n,-1));
        // vector<vector<int>> map(m,vector<int>(n,0));
        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++ret;
                    dfs(i, j, grid);
                }
            }
        }
        return ret;
    }
};