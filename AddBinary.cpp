#include <iostream>
#include <string>
using namespace std;
string addBinary(string a, string b) {
        int length1 = a.size();
        int length2 = b.size();
        int index = max(length1, length2);
        int index1 = length1-1;
        int index2 = length2-1;
        int carry = 0;
        char *resultArray = new char[index + 1];
        while(index1 >= 0 && index2 >= 0){
            int tempA = a[index1--] - '0';
            int tempB = b[index2--] - '0';
            int temp = tempA + tempB + carry;
            resultArray[index--] = temp % 2 + '0';
            carry = temp / 2;
        }
        while(index1 >= 0){
        	int tempA = a[index1--] - '0';
        	int temp = tempA + carry;
        	resultArray[index--] = temp % 2 + '0';
        	carry = temp / 2;
        }
        while(index2 >= 0){
        	int tempB = b[index2--] - '0';
        	int temp = tempB + carry;
        	resultArray[index--] = temp % 2 + '0';
        	carry = temp / 2;
        }
        if(carry == 1){
        	resultArray[index--] = carry + '0';
        	string result(resultArray);
        	return result;
        }else{
        	resultArray[index--] = '0';
        	string result(resultArray);
        	result.erase(0,1);
        	return result;
        }
    }
    
int main(){
	cout<<addBinary("11","1")<<endl;
	return 0;
}