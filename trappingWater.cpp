#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
        int water = 0;
        int size = height.size(), start = 0, end = height.size() - 1;
        while(start < end) {
            if(height[start] <= height[end]) {
                int prev = start;
                start ++;
                while(start < end && height[start] < height[prev]) {
                    water += height[prev] - height[start];
                    start ++;
                }
            } else {
                int back = end;
                end --;
                while(end > start && height[end] < height[back]) {
                    water += height[back] - height[end];
                    end --;
                }
            }
        }
        return water;
    }
    
    int main() {
    	vector<int> height(12);
    	height[0]=0;height[1]=1;height[2]=0;height[3]=2;height[4]=1;
    	height[5]=0;height[6]=1;height[7]=3;height[8]=2;height[9]=1;
    	height[10]=2;height[11]=1;
    	cout<<trap(height)<<endl;
    	return 0;
    }