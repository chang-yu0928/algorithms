#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size(), i = 0, maxNum = INT_MIN, maxInd = 0;
        vector<int> result;
        if(len == 0) return result;
        while(i <= len - k) {
            for(int j = i;j < i + k;j ++) {
                if(maxNum < nums[j]) {
                    maxNum = nums[j];
                    maxInd = j;
                }
            }
            result.push_back(maxNum);
            i ++;
            while(i <= len - k && i < maxInd) {
                if(maxNum < nums[i+k-1]) {
                    maxNum = nums[i+k-1];
                    maxInd = i + k - 1;
                }
                result.push_back(maxNum);
                i ++;
            }
            maxNum = INT_MIN;
        }
        return result;
    }
    
    int main() {
    	int x[] = {-7,-8,7,5,7,1,6,0};
    	vector<int> nums(x, x + sizeof(x)/sizeof(int));
    	vector<int> result = maxSlidingWindow(nums, 4);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    }