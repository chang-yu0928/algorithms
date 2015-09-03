#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
    double result = (double)numerator/(double)denominator;
    stringstream ss;
    ss << result;
    return ss.str();
}
int main(){
	cout<<fractionToDecimal(1,1)<<endl;
	return 0;
}