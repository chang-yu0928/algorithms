#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        while(m > 0 && n > 0) {
            if(nums1[m-1] > nums2[n-1]) nums1[index --] = nums1[-- m];
            else nums1[index --] = nums2[-- n];
        }
        while(m > 0) nums1[index --] = nums1[-- m];
        while(n > 0) nums1[index --] = nums2[-- n];
    }
    
    int main() {
    	vector<int> nums1(1), nums2;
    	nums1[0] = 1;
    	merge(nums1, 1, nums2, 0);
    	for(int i = 0;i < nums1.size();i ++) {
    		cout<<nums1[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }