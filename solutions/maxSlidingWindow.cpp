#include <iostream>
#include <deque>
#include <vector>

using namespace std;

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> container;
        vector<int> result;
        int maxIndex = -1;
        int max = INT_MIN;
        for(int i = 0;i < nums.size();i ++) {
            if(i <= k - 1) {
                container.push_back(nums[i]);
                if(i == k - 1) {
                	for(int j = 0;j < container.size();j ++) {
	            		if(max < container[j]) {
	                        max = container[j];
	                        maxIndex = i - k + j;
	                    }
		            }
		        	result.push_back(max);
                }
            } else {
            	container.pop_front();
                container.push_back(nums[i]);
                if(i - maxIndex >= k) {
                	max = INT_MIN;
                    for(int j = 0;j < container.size();j ++) {
                        if(max < container[j]) {
                            max = container[j];
                            maxIndex = i - k + j;
                        }
                    }
                }
                if(nums[i] > max) {
                	max = nums[i];
                	maxIndex = i;
                }
                result.push_back(max);
            }
        }
        return result;
    }
    
    int main() {
    	vector<int> nums;
    	nums.push_back(1);
    	nums.push_back(3);
    	nums.push_back(-1);
    	nums.push_back(-3);
    	nums.push_back(5);
    	nums.push_back(3);
    	nums.push_back(6);
    	nums.push_back(7);
    	
    	vector<int> result = maxSlidingWindow(nums, 3);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    }