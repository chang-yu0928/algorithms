#include <iostream>

using namespace std;

int countDigitOne(int n);
int countDigitOne(int n, int seg) {
	if(n == 0) {
		return 0;
	}
	if(n < 10 || seg == 1) {
		return 1;
	}
	if(n / seg == 1) {
		return countDigitOne(n - n / seg * seg) + countDigitOne(seg - 1) + n - n / seg * seg + 1;
	}
	return (n / seg) * countDigitOne(seg - 1) + countDigitOne(n - n / seg * seg) + seg;
}


int countDigitOne(int n) {
	int segment = 1, x = n / segment;
	while(x >= 10) {
		segment *= 10;
		x = n / segment;
	}
	return countDigitOne(n, segment);
}

int main() {
	cout<<countDigitOne(11)<<endl;
	return 0;
}