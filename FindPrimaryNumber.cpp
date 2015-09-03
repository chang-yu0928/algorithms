#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool checkPrimary(int num, vector<int> &primarySet) {
	for(int i = 2;i <= sqrt(num);i ++) {
		if(num % i == 0){
			return false;
		}
	}
	return true;
}

int findPrimaryNumber(int n) {
	vector<int> primarySet;
	primarySet.push_back(2);
	int count = 1;
	for(int i = 3;i < n;i ++) {
		if(checkPrimary(i, primarySet)) {
			count ++;
		}
	}
	return count;
}

int main() {
	cout<<findPrimaryNumber(1000000)<<endl;
	return 0;
}