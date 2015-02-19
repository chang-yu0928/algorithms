#include <iostream>
using namespace std;

int atoi(const char *str) {
        const char *temp = str;
        bool minus = false;
        bool plus = false;
        bool endOfSeq = false;
        int exceed = 0;
        int result = 0;
        while(*temp == ' '){
        	temp ++;
        }
        while(*temp != '\0'){
        	switch(*temp){
        		case '-': minus = true; break;
        		case '+': plus = true; break;
        		case '1': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 1; break;
        		case '2': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 2; break;
        		case '3': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 3; break;
        		case '4': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 4; break;
        		case '5': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 5; break;
        		case '6': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 6; break;
        		case '7': if(exceed >= 2){ exceed = 3; break;} result = result * 10 + 7; break;
        		case '8': if(exceed >= 2 || (exceed == 1 && minus == false)) { exceed = 3; break;} result = result * 10 + 8; break;
        		case '9': if(exceed >= 1){ exceed = 3; break;} result = result * 10 + 9; break;
        		case '0': if(exceed >= 1){ exceed = 3; break;} result = result * 10; break;
        		default: endOfSeq = true; break;
        	}
        	if(minus && plus){
        		return 0;
        	}
        	if(endOfSeq){
        		break;
        	}
        	if(exceed == 3){
        		if(minus)
        			return INT_MIN;
        		else
        			return INT_MAX;
        	}
        	if(result > 214748364){
        		exceed = 2;
        	}
        	if(result == 214748364){
        		exceed = 1;
        	}
        	
        	temp ++;
        }
        if(minus)
        	return result*(-1);
        else
        	return result;
    }
    
int main(){
	char input[] = {'-', '2', '1', '4', '7', '4', '8', '3', '6', '4', '9', '\0'};
	cout<<atoi(input)<<endl;
	return 0;
}