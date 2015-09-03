#include <iostream>
#include <string>

using namespace std;

	string getPermutation(int n, int k) {
		k -= 1;
        string nums;
        int *range = new int[n];
        int count = 1;
        nums += '1';
        for(int i = 1;i < n;i ++) {
        	count *= i;
        	range[i] = count;
        	nums += (i + '1');

        }
        int start = n - 1;
        string result;
        while(start >= 1) {
        	if(k < range[start]) {
        		result += nums[0];
        		nums.erase(0, 1);
        	} else {
        		int x = k / range[start];
        		result += nums[x];
        		nums.erase(x, 1);
        		k = k % range[start];
        	}
        	start --;
        }
        result += nums[0];
        return result;
    }

int main() {
	cout<<getPermutation(9,4)<<endl;
	return 0;
}