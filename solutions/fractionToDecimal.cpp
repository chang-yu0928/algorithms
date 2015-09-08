#include <iostream>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
	string res;
	long numer, denom, dummy;
	unordered_map<long, int> mp;
	if((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) res += "-";
	numer = (numerator < 0) ? (long)numerator * (-1) : (long)numerator;
	denom = (denominator < 0) ? (long)denominator * (-1) : (long)denominator;
	res += to_string(numer / denom);
	long remain = numer % denom;
	if(remain == 0) return res;
	res += ".";
	remain *= 10;
	while(remain) {
		dummy = remain / denom;
		if(mp.count(remain)) {
			res.insert(mp[remain], 1, '(');
			res += ')';
			break;
		}
		mp[remain] = res.size();
		res += to_string(dummy);
		remain = (remain % denom) * 10;
	}
	return res;
}

int main() {
	cout<<fractionToDecimal(-1, -2147483648)<<endl;
	return 0;
}