#include <iostream>
#include <vector>
using namespace std;
int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int length = num.size();
        if(num.size() < 3){
        	return -1;
        }
        int result = num[0]+num[1]+num[2];
        for(int i = 0;i < length;i ++){
            if(i > 0 && num[i] == num[i-1])
                continue;
            for(int j = i+1, k=length-1;j < k;){
                int sum = num[i]+num[j]+num[k];
                if(abs(result-target) > abs(sum - target)){
                    result = sum;
                }
                if(sum - target > 0){
                    while(num[k] == num[k-1]){
                        k --;
                    }
                    k --;
                }else{
                    while(num[j] == num[j+1]){
                        j ++;
                    }
                    j ++;
                }
            }
        }
        return result;
    }
    
int main(){
	vector<int> input;
	input.push_back(1); input.push_back(1); input.push_back(-1); input.push_back(-1); input.push_back(3);
	cout<<threeSumClosest(input, -1)<<endl;
	return 0;
}