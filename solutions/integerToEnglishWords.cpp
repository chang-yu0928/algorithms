#include <iostream>
#include <string>

using namespace std;

	string judge(int num) {
		if(num == 0) return "";
        string result;
        int dummy;
        while(num) {
        	dummy = 0;
            if(num >= 20) {
                dummy = num % 10;
                num = num - dummy;
            }
            switch(num) {
                case 1 : result += "One"; break;
                case 2 : result += "Two"; break;
                case 3 : result += "Three"; break;
                case 4 : result += "Four"; break;
                case 5 : result += "Five"; break;
                case 6 : result += "Six"; break;
                case 7 : result += "Seven"; break;
                case 8 : result += "Eight"; break;
                case 9 : result += "Nine"; break;
                case 10 : result += "Ten"; break;
                case 11 : result += "Eleven"; break;
                case 12 : result += "Twelve"; break;
                case 13 : result += "Thirteen"; break;
                case 14 : result += "Fourteen"; break;
                case 15 : result += "Fifteen"; break;
                case 16 : result += "Sixteen"; break;
                case 17 : result += "Seventeen"; break;
                case 18 : result += "Eighteen"; break;
                case 19 : result += "Nineteen"; break;
                case 20 : result += "Twenty"; break;
                case 30 : result += "Thirty"; break;
                case 40 : result += "Forty"; break;
                case 50 : result += "Fifty"; break;
                case 60 : result += "Sixty"; break;
                case 70 : result += "Seventy"; break;
                case 80 : result += "Eighty"; break;
                case 90 : result += "Ninety"; break;
            }
            num = dummy;
            if(num) result += " ";
        }
        return result;
    }
    
    string key(int num) {
        switch(num) {
            case 1000 : return "Thousand";
            case 1000000 : return "Million";
            case 1000000000 : return "Billion";
        }
        return "";
    }

    string number(int num) {
        string res;
        if(num >= 100) {
            int dummy = num / 100;
            num = num % 100;
            if(num) res += (judge(dummy) + " Hundred ");
            else res += (judge(dummy) + " Hundred");
        }
        res += judge(num);
        return res;
    }

    string numberToWords(int num) {
        if(!num) return "Zero";
        int digit = 1000000000;
        string result;
        while(num) {
            int dummy = num / digit;
            num %= digit;
            if(dummy) {
                if(!result.empty()) {
                	if(digit == 1) result += (" " + number(dummy));
                	else result += (" " + number(dummy) + " " + key(digit));
                } else {
                	if(digit == 1) result += number(dummy);
                	else result += (number(dummy) + " " + key(digit));
                }
            }
            digit /= 1000;
        }
        return result;
    }
    
    int main(int args, char** argv) {
    	cout<<numberToWords(atoi(argv[1]))<<endl;
    	return 0;
    }