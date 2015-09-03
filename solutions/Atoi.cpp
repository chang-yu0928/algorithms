#include <iostream>
#include <vector>
using namespace std;

int atoi(string str) {
        bool negative = false; 
    	bool positive = false;
    	int result = 0;
    	int index = 0;
    	while(str[index] == ' ') {
    	    index ++;
    	}
    	for(int i = index;i < str.size();i ++) {
    		if(str[i] == '+') {
    			if(negative || positive) {
    				return 0;
    			}
    			positive = true;
    		} else if(str[i] == '-') {
    			if(negative || positive) {
    				return 0;
    			}
    			negative = true;
    		} else if(str[i] <= '9' && str[i] >= '0') {
    			if(result > (INT_MAX / 10)) {
    			    if(negative) {
    			        return INT_MIN;
    			    }
    				return INT_MAX;
    			} else if(result == (INT_MAX / 10)) {
    				if(!negative && str[i] - '0' > 7) {
    					return INT_MAX;
    				}
    				if(negative && str[i] - '0' > 8) {
    					return INT_MIN;
    				}
    			}
    			result = result * 10 + str[i] - '0';
    		} else {
    		    break;
    		}
    	}
    	if(negative) {
    		return (-1) * result;
    	}
    	return result;
    }

int main() {
	cout<<atoi("  -0012 42")<<endl;
	return 0;
}