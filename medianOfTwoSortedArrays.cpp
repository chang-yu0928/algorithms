#include <iostream>
#include <vector>
using namespace std;

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int m1, int m2) {
        int mid1 = n1 + ((n2 - n1) >> 1);
        int mid2 = m1 + ((m2 - m1) >> 1);
        cout<<mid1<<","<<mid2<<endl;
        if(nums1[mid1] > nums2[mid2]) {
        	return findMedianSortedArrays(nums1, nums2, n1, mid1, mid2, m2);
        } else if(nums1[mid1] < nums2[mid2]) {
        	return findMedianSortedArrays(nums1, nums2, mid1, n2, m1, mid2);
        } else {
        	return (double)(nums1[mid1] + nums2[mid2]) / 2;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int len1 = nums1.size(), len2 = nums2.size();
        if(len1 == 0 && len2 == 0) return 0;
        if(len1 == 0) return (nums2[len2/2] + nums2[(len2-1)/2])/2;
        if(len2 == 0) return (nums1[len1/2] + nums1[(len1-1)/2])/2;
        return findMedianSortedArrays(nums1, nums2, 0, len1 - 1, 0, len2 - 1);
    }
    
    
    int main() {
    	vector<int> nums1(1), nums2(5);
    	nums1[0]=1;//nums1[1]=3;//nums1[2]=5;
    	nums2[0]=2;nums2[1]=3;nums2[2]=4;nums2[3]=5;nums2[4]=6;
    	cout<<findMedianSortedArrays(nums1, nums2)<<endl;
    	return 0;
    }