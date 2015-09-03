#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, len = nums.size(), res = 0, diff = INT_MAX, temp, left, right, tempDiff;
        for(i = 0;i < len;i ++) {
            left = i + 1;
            right = len - 1;
            while(left < right) {
                temp = nums[i] + nums[left] + nums[right];
                tempDiff = abs(temp - target);
                if(diff > tempDiff) {
                    diff = tempDiff;
                    res = temp;
                }
                if(temp < target) left ++;
                else right --;
            }
        }
        return res;
    }
    
int main(){
	vector<int> input;
	//input.push_back(1); //input.push_back(1); //input.push_back(-1); input.push_back(-1); input.push_back(3);
	cout<<threeSumClosest(input, -1)<<endl;
	return 0;
}