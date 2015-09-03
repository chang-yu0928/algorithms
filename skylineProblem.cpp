#include <iostream>
#include <vector>
#include <queue>
using namespace std;

	struct compare {
        bool operator()(const pair<int, int> pair1, const pair<int, int> pair2) {
            if(pair1.first < pair2.first) return true;
            else if(pair1.first > pair2.first) return false;
            else return (pair1.second < pair2.second);
        }
    };

    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, compare> live;
        vector<pair<int, int> > result;
        int len = buildings.size(), i = 0;
        while(i < len) {
            if(live.empty() || live.top().second >= buildings[i][0]) {
                int hMax = buildings[i][2], left = buildings[i][0], prev = (!live.empty()) ? live.top().first : 0;
                live.push(make_pair(buildings[i][2], buildings[i][1]));
                while(i + 1 < len && buildings[i][0] == buildings[i+1][0]) {
                	i ++;
                    hMax = max(buildings[i][2], hMax);
                    live.push(make_pair(buildings[i][2], buildings[i][1]));
                }
                if(hMax > prev) result.push_back(make_pair(left, hMax));
                i ++;
            } else {
                int height = live.top().first, right = live.top().second;
                live.pop();
                while(!live.empty() && live.top().second < right) live.pop();
                if(!live.empty()) result.push_back(make_pair(right, live.top().first));
                else result.push_back(make_pair(right, 0));
            }
        }
        while(!live.empty()) {
        	int height = live.top().first, right = live.top().second;
            live.pop();
            while(!live.empty() && live.top().second <= right) live.pop();
            if(live.empty()) result.push_back(make_pair(right, 0));
            else if(live.top().first != height) result.push_back(make_pair(right, live.top().first));
        }
        return result;
    }
    
    int main() {
    	//[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]
    	vector<vector<int> > buildings(5, vector<int>(3));
    	buildings[0][0]=2;buildings[0][1]=9;buildings[0][2]=10;
    	buildings[1][0]=3;buildings[1][1]=7;buildings[1][2]=15;
    	buildings[2][0]=5;buildings[2][1]=12;buildings[2][2]=12;
    	buildings[3][0]=15;buildings[3][1]=20;buildings[3][2]=10;
    	buildings[4][0]=19;buildings[4][1]=24;buildings[4][2]=8;
    	
    	//[1,2,1],[1,2,2],[1,2,3]
    	// vector<vector<int> > buildings(3, vector<int>(3));
    	// buildings[0][0]=1;buildings[0][1]=2;buildings[0][2]=1;
    	// buildings[1][0]=1;buildings[1][1]=2;buildings[1][2]=2;
    	// buildings[2][0]=1;buildings[2][1]=2;buildings[2][2]=3;
    	
    	//[[0,2,3],[2,5,3]]
    	// vector<vector<int> > buildings(3, vector<int>(3));
    	// buildings[0][0]=0;buildings[0][1]=2;buildings[0][2]=3;
    	// buildings[1][0]=2;buildings[1][1]=5;buildings[1][2]=3;
    	
    	//[[0,5,7],[5,10,7],[5,10,12],[10,15,7],[15,20,7],[15,20,12],[20,25,7]]
    	// vector<vector<int> > buildings(7, vector<int>(3));
    	// buildings[0][0]=0;buildings[0][1]=5;buildings[0][2]=7;
    	// buildings[1][0]=5;buildings[1][1]=10;buildings[1][2]=7;
    	// buildings[2][0]=5;buildings[2][1]=10;buildings[2][2]=12;
    	// buildings[3][0]=10;buildings[3][1]=15;buildings[3][2]=7;
    	// buildings[4][0]=15;buildings[4][1]=20;buildings[4][2]=7;
    	// buildings[5][0]=15;buildings[5][1]=20;buildings[5][2]=12;
    	// buildings[6][0]=20;buildings[6][1]=25;buildings[6][2]=7;
    	
    	vector<pair<int, int> > res = getSkyline(buildings);
    	for(int i = 0;i < res.size();i ++) {
    		cout<<res[i].first<<" "<<res[i].second<<endl;
    	}
    	return 0;
    }