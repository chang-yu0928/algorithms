#include <iostream>
#include <vector>

using namespace std;

	vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length);
        int pro = 1;
        for(int i = 0;i < length;i ++) {
            result[i] = pro;
            pro *= nums[i];
        }
        pro = 1;
        for(int i = length - 1;i >= 0;i --) {
            result[i] *= pro;
            pro *= nums[i];
        }
        return result;
    }
    
    int main() {
    	vector<int> input;
    	input.push_back(1);
    	input.push_back(2);
    	input.push_back(3);
    	input.push_back(4);
    	
    	vector<int> result = productExceptSelf(input);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    }