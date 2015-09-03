#include <iostream>
using namespace std;

int removeElement(int A[], int n, int elem) {
        int tail = n - 1;
        for(int i = 0;i < n;i ++){
            if(A[i] == elem){
                while(A[tail] == elem){
                    tail --;
                }
                if(tail == -1){
                    return 0;
                }else{
                    if(i < tail){
                    	A[i] = A[tail];
                        n = tail;
                        tail --;
                        cout<<tail<<endl;
                    }
                }
            }
        }
        return tail+1;
    }
    
int main(){
	int A[2] = {4,5};
	cout<<removeElement(A, 2, 4)<<endl;
	return 0;
}