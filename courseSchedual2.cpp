#include <iostream>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > requisites(numCourses);
        vector<int> countCourses(numCourses, 0);
        vector<int> result;
        int i, j;
        for(i = 0;i < prerequisites.size();i ++) {
            requisites[prerequisites[i].second].push_back(prerequisites[i].first);
            countCourses[prerequisites[i].first] ++;
        }
        while(result.size() != numCourses) {
            for(i = 0;i < countCourses.size();i ++) {
                if(countCourses[i] == 0) {
                	countCourses[i] = -1;
                	break;
                }
            }
            if(i == countCourses.size()) break;
            for(j = 0;j < requisites[i].size();j ++) {
                countCourses[requisites[i][j]] --;
            }
            result.push_back(i);
        }
        if(result.size() != numCourses) {
            result.clear();
            return result;
        } else {
            return result;
        }
    }
    
    int main() {
    	vector<pair<int, int> > prerequisites;
    	pair<int, int> temp;
    	temp.first = 1;
    	temp.second = 0;
    	prerequisites.push_back(temp);
    	temp.first = 2;
    	temp.second = 0;
    	prerequisites.push_back(temp);
    	temp.first = 3;
    	temp.second = 1;
    	prerequisites.push_back(temp);
    	temp.first = 3;
    	temp.second = 2;
    	prerequisites.push_back(temp);
    	vector<int> result = findOrder(4, prerequisites);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }