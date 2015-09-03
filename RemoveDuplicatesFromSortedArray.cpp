#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) {
            return 0;
        }
        int prev = nums[0], p = 1, count = 1, i = 1;
        while(i < len) {
            while(i < len && nums[i] == prev) {
                i ++;
            }
            if(i < len) {
                prev = nums[i];
                swap(nums[i], nums[p]);
                count ++;
                p ++;
                i ++;
            }
        }
        return count;
    }
    
    int main() {
        vector<int> nums(4);
        nums[0]=1;nums[1]=1;nums[2]=2;nums[3]=2;//nums[4]=4;
        int len = removeDuplicates(nums);
        for(int i = 0;i < len;i ++) {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        return 0;
    }