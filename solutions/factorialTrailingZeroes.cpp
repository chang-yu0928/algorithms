#include <iostream>
using namespace std;

int trailingZeroes(int n) {
        int count = 0;
        while( n /= 5) count += n;
        return count;
    }
    
    int main(int args, char **argv) {
    	int input = atoi(argv[1]);
    	cout<<trailingZeroes(input)<<endl;
    	return 0;
    }