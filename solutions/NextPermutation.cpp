#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &num, int start){
        int i = start, j = num.size() - 1;
        cout<<i <<j <<endl;
        while(i < j){
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i ++;
            j --;
        }
    }
    
void nextPermutation(vector<int> &num) {
        int i = 0;
        for(i = num.size() - 2;i >= 0;i --){
            if(num[i] < num[i+1]){
                break;
            }
        }
        cout<< i<<endl;
        reverse(num, i+1);
        if(i == -1) return;
        int j = 0;
        int small = i+1;
        for(j = i+1;j < num.size();j ++){
            if(num[small] > num[j]){
                small = j;
            }
        }
        int temp = num[i];
        num[i] = num[small];
        num[small] = temp;
    }
    
    
    
int main(){
	vector<int> result;
	result.push_back(1);
	result.push_back(2);
	
	nextPermutation(result);
	for(int i = 0;i < result.size();i ++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
