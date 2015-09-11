#include <iostream>
#include <vector>
#include <queue>
using namespace std;

    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > pre(numCourses);
        vector<int> courCoun(numCourses, 0);
        queue<int> freeCour;
        for(int i = 0;i < prerequisites.size();i ++) {
            pre[prerequisites[i].second].push_back(prerequisites[i].first);
            courCoun[prerequisites[i].first] ++;
        }
        for(int i = 0;i < courCoun.size();i ++) {
        	if(courCoun[i] == 0) freeCour.push(i);
        }
        while(!freeCour.empty()) {
        	int curr = freeCour.front();
        	for(int i = 0;i < pre[curr].size();i ++) {
        		courCoun[pre[curr][i]] --;
        		if(courCoun[pre[curr][i]] == 0) freeCour.push(pre[curr][i]);
        	}
        	freeCour.pop();
        }
        for(int i = 0;i < numCourses;i ++) {
        	if(courCoun[i] > 0) return false;
        }
        return true;
    }
    
    int main() {
    	vector<pair<int, int> > pre;
    	pre.push_back(make_pair(0 , 1));
    	pre.push_back(make_pair(0 , 2));
    	pre.push_back(make_pair(1 , 2));
    	cout<<canFinish(3, pre)<<endl;
    	return 0;
    }