#include <iostream>
#include <string>
using namespace std;
int romanToInt(string s) {
        int result = 0;
        for(int i = 0;i < s.size();i ++){
            switch(s[i]){
            	case 'I':{
            		result ++;
            		break;
            	};
            	case 'V':{
            		if(i != 0){
            			if(s[i-1] == 'I'){
            				result += 3;
            				break;
            			}
            		}
            		result += 5;
            		break;
            	};
            	case 'X':{
            		if(i != 0){
            			if(s[i-1] == 'I'){
            				result += 8;
            				break;
            			}
            		}
            		result += 10;
            		break;
            	};
            	case 'L':{
            		if(i != 0){
            			if(s[i-1] == 'X'){
            				result += 30;
            				break;
            			}
            		}
            		result += 50;
            		break;
            	};
            	case 'C':{
            		if(i != 0){
            			if(s[i-1] == 'X'){
            				result += 80;
            				break;
            			}
            		}
            		result += 100;
            		break;
            	};
            	case 'D':{
            		if(i != 0){
            			if(s[i-1] == 'C'){
            				result += 300;
            				break;
            			}
            		}
            		result += 500;
            		break;
            	};
            	case 'M':{
            		if(i != 0){
            			if(s[i-1] == 'C'){
            				result += 800;
            				break;
            			}
            		}
            		result += 1000;
            		break;
            	};
            	default :{
            		break;
            	};
            }
        }
        return result;
    }
int main(){
	cout<<romanToInt("VI")<<endl;
	return 0;
}