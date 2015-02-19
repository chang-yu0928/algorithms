#include <iostream>
using namespace std;

int maxProduct(int A[], int n){

	int result = A[0];
	int max = A[0];
	int min = A[0];
	int zero = -2;
	cout<<"max:"<<max<<", min:"<<min<<", result:"<<result<<endl;
	for(int i = 1;i < n;i ++){
		if(i == zero + 1){
			max = A[i];
			min = A[i];
			if(max > result)
				result = max;
			continue;
		}
		if(A[i] == 0){
			zero = i;
		}
		max = max * A[i];
		min = min * A[i];
		if(max < min){
			int temp = max;
			max = min;
			min = temp;
		}
		if(max < A[i]){
			max = A[i];
		}
		if(A[i] < min){
			min = A[i];
		}
		if(result < max){
			result = max;
		}
		cout<<"max:"<<max<<", min:"<<min<<", result:"<<result<<endl;
	}
	cout<<"max:"<<max<<", min:"<<min<<", result:"<<result<<endl;
	if(max > result){
		result = max;
	}
	return result;
}

int main(){
	int a[] = {-2,0,1,-3};
	cout<<maxProduct(a,4)<<endl;
	return 0;
}