#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0, j = 0, len = intervals.size();
        vector<Interval> result;
        if(len == 0) {
        	result.push_back(newInterval);
        	return result;
        }
        while(i < len && intervals[i].end < newInterval.start) {
            result.push_back(intervals[i]);
            i ++;
        }
        j = i;
        while(j < len && intervals[j].start <= newInterval.end) {
            j ++;
        }
        newInterval.start = (i < len) ? min(intervals[i].start, newInterval.start) : newInterval.start;
        newInterval.end = (j > 0) ? max(intervals[j-1].end, newInterval.end) : newInterval.end;
        result.push_back(newInterval);
        while(j < len) {
            result.push_back(intervals[j]);
            j ++;
        }
        return result;
    }
    
    int main() {
    	Interval inter;
    	vector<Interval> intervals;
    	inter.start = 1;
    	inter.end = 5;
    	intervals.push_back(inter);
    	vector<Interval> result = insert(intervals, Interval(0,1));
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i].start<<" "<<result[i].end<<", ";
    	}
    	cout<<endl;
    	return 0;
    }