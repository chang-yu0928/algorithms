#include <iostream>
#include <cmath>
using namespace std;

int sqrt(int x) {
        if(x <= 1){
            return x;
        }
        double start = 0, end = x;
        double result = (start + end) / 2;
        while(abs(start-end) >= 0.000001){
            if(result * result < x){
                start = result;
            }else{
                end = result;
            }
            result = (start + end) / 2.0;
        }
        return static_cast<int> (end);
    }
    
int main(){
	cout<<sqrt(16)<<endl;
	return 0;
}