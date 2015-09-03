#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void roman(string &result, int digit, string nine, string five, string four, char one) {
        if(digit == 9) {
            result += nine;
        } else {
            if(digit >= 5) {
                digit -= 5;
                result += five;
            }
            if(digit == 4) result += four;
            else result += string(digit, one);
        }
    }
    
    string intToRoman(int num) {
        string result;
        int m = num/1000;
        result += string(m, 'M');
        num = num % 1000;
        roman(result, num / 100, "CM", "D", "CD", 'C');
        num = num % 100;
        roman(result, num / 10, "XC", "L", "XL", 'X');
        num = num % 10;
        roman(result, num, "IX", "V", "IV", 'I');
        return result;
    }
    
    
    int main(int args, char **argv) {
    	int input = atoi(argv[1]);
    	cout<<intToRoman(input)<<endl;
    	return 0;
    }