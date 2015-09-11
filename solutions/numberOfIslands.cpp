#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char> > &grid, int m, int n) {
        if(m < 0 || m >= grid.size() || n < 0 || n >= grid[0].size() || grid[m][n] != '1') return;
        grid[m][n] = '.';
        dfs(grid, m - 1, n);
        dfs(grid, m + 1, n);
        dfs(grid, m, n - 1);
        dfs(grid, m, n + 1);
    }

    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0;i < m;i ++) {
            for(int j = 0;j < n;j ++) {
                if(grid[i][j] == '1') {
                    res ++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
    
    int main() {
    	vector<vector<char> > grid(1, vector<char>(2));
    	grid[0][0] = '1';grid[0][1] = '1';
    	cout<<numIslands(grid)<<endl;
    	return 0;
    }