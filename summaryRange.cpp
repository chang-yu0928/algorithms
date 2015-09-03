#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
        int i = 0, len = nums.size(), start;
        vector<string> result;
        while(i < len) {
            start = i;
            while(i + 1 < len && nums[i+1] == nums[i] + 1) {
                i ++;
            }
            if(start != i) result.push_back(to_string(nums[start]) + "->" + to_string(nums[i]));
            else result.push_back(to_string(nums[start]));
            i ++;
        }
        return result;
    }
    
    int main() {
    	vector<int> input;
    	input.push_back(0);
    	input.push_back(1);
    	input.push_back(2);
    	input.push_back(4);
    	input.push_back(5);
    	input.push_back(7);
    	vector<string> result = summaryRanges(input);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }