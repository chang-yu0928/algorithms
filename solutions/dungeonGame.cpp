#include <iostream>
#include <vector>
using namespace std;

	int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > con(m, vector<int>(n));
        for(int i = m - 1;i >= 0;i --) {
            for(int j = n - 1;j >= 0;j --) {
                if(i == m - 1 && j == n - 1) {
                    con[i][j] = 1 - dungeon[i][j];
                } else if(i == m - 1) {
                    con[i][j] = con[i][j+1] - dungeon[i][j];
                } else if(j == n - 1) {
                    con[i][j] = con[i+1][j] - dungeon[i][j];
                } else {
                    con[i][j] = min(con[i+1][j] - dungeon[i][j], con[i][j+1] - dungeon[i][j]);
                }
                if(con[i][j] <= 0) con[i][j] = 1;
            }
        }
        return con[0][0];
    }
    
    int main() {
    	vector<vector<int> > dungeon(3, vector<int>(3));
    	dungeon[0][0]=-2;dungeon[0][1]=-3;dungeon[0][2]=3;
    	dungeon[1][0]=-5;dungeon[1][1]=-10;dungeon[1][2]=1;
    	dungeon[2][0]=10;dungeon[2][1]=30;dungeon[2][2]=-5;
    	cout<<calculateMinimumHP(dungeon)<<endl;
    	return 0;
    }