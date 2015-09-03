#include <iostream>
using namespace std;

void reverse(char* str){
	//count length of str
	int length;
	while(str[length] != NULL){
		length ++;
	}
	if(length == 0 || length == 1)
		return;
	int start = 0, end = length - 1;
	while(start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start ++;
		end --;
	}
}

int main(){
	char *input = new char[4];
	char *temp = input;
	*input = 'a'; input ++;
	*input = 'b'; input ++;
	*input = 'c'; input ++;
	input = NULL;
	reverse(temp);
	for(int i = 0;i < 3;i ++){
		cout<<temp[i]<<endl;
	}
}
