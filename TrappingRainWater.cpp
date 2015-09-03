#include <iostream>
#include <vector>
using namespace std;

    int trap(vector<int> &height) {
        int len = height.size();
        if(len == 0) {
            return 0;
        }
        int prev = 0, back = len - 1, result = 0;
        while(prev < back) {
            if(height[prev] < height[back]) {
                for(int i = prev + 1;i <= back;i ++) {
                    if(height[i] >= height[prev]) {
                        prev = i;
                        break;
                    }
                    result += height[prev] - height[i];
                }
            } else {
                for(int i = back - 1;i >= prev;i --) {
                    if(height[i] >= height[back]) {
                        back = i;
                        break;
                    }
                    result += height[back] - height[i];
                }
            }
        }
        return result;
    }
    
int main(){
    int A[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(A, A + sizeof(A) / sizeof(int));
    cout<<trap(height)<<endl;
    return 0;
}