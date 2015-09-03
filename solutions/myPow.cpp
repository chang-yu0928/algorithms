#include <iostream>
#include <unordered_map>

using namespace std;

double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }
        double num = (n > 0) ? pow(x, n/2) : pow(x = 1/x, -(n/2));
        return num * num * ((n%2) ? x : 1);
    }
    
    int main() {
    	cout<<myPow(8.88023, 3)<<endl;
    	return 0;
    }