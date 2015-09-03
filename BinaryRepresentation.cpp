#include <iostream>
#include <string>
using namespace std;

string printBinary(double num) {
	if(num >= 1 || num < 0) {
		return "Error";
	}
	
	string result;
	result += '.';
	double factor = 0.5;
	while(num > 0) {
		num -= factor;
		if(num >= 0) {
			result += '1';
		} else {
			result += '0';
			num += factor;
		}
		factor /= 2;
		
		if(result.size() >= 32) {
			return "Error";
		}
	}
	return result;
}

int main() {
	cout<<printBinary(0.625)<<endl;
	return 0;
}