#include <iostream>
using namespace std;

bool canJump(int A[], int n) {
        //greedy
        if(n == 1) {
            return true;
        }
        bool flag = true;
        for(int i = n-2;i >= 0;i --) {
            if(A[i] == 0) {
            	cout<<i<<endl;
                flag = false;
                int j = i - 1;
                while(j >= 0) {
                    if(A[j] + j > i) {
                        i = j;
                        flag = true;
                        break;
                    }
                    j --;
                }
                if(j == -1) return false;
            }
        }
        return flag;
    }
    
int main() {
	int a[9] = {0,3,1,0,4,3,2,0,1};
	cout<<"result:"<<canJump(a, 9)<<endl;
	return 0;
}