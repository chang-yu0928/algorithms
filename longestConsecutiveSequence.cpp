#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
        int len = nums.size(), length = 0, longest = 0, curr;
        unordered_set<int> numSet;
        for(int i = 0;i < len;i ++) {
            numSet.insert(nums[i]);
        }
        for(int i = 0;i < len;i ++) {
            curr = nums[i];
            if(numSet.count(curr)) {
            	length ++;
                int temp = curr;
                while(numSet.count(++temp)) {
                    length ++;
                    numSet.erase(temp);
                }
                while(numSet.count(--curr)) {
                    length ++;
                    numSet.erase(curr);
                }
                longest = max(longest, length);
                length = 0;
            }
        }
        return longest;
    }
    
    int main() {
    	int n[] = {100, 4, 200, 1, 3, 2};
    	vector<int> nums(n, n + sizeof(n) / sizeof(int));
    	cout<<longestConsecutive(nums)<<endl;
    	return 0;
    }