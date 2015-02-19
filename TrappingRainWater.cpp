#include <iostream>
using namespace std;

int trap(int A[], int n) {
        int index1 = 0;
        int result = 0;
        bool flag = true;
        for(int i = 0;i < n;i ++){
            if(flag && i == 0 && A[i] > A[i+1]){
                flag = false;
                index1 = i;
            }else if(flag && A[i] > A[i+1] && A[i] >= A[i-1]){
                flag = false;
                index1 = i;
            }else if(!flag && i == n-1 && A[i] > A[i-1]){
                int temp = min(A[index1], A[i]);
                for(int j = index1 + 1;j < i;j ++){
                    if(temp-A[j] > 0){
                        result += temp - A[j];
                    }
                }
            }else if(!flag && A[i] >= A[i+1] && A[i] > A[i-1]){
                int temp = min(A[index1], A[i]);
                for(int j = index1 + 1;j < i;j ++){
                    if(temp-A[j] > 0){
                        result += temp - A[j];
                    }
                }
                flag = true;
            }
        }
        cout<<index1<<endl;
        return result;
    }
    
int main(){
    int A[6]={5,2,1,2,1,5};
    cout<<trap(A,6)<<endl;
    return 0;
}