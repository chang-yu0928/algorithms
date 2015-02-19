#include <iostream>
using namespace std;
int strStr(char *haystack, char *needle) {
    int lengthHaystack = strlen(haystack);
    int lengthNeedle = strlen(needle);
    int *next = new int[lengthNeedle+1];
    next[0] = -1;
    int k = -1;
    int i = 0;
    int j = 0;
    while(j < lengthNeedle - 1){
    	if(k == -1 || needle[j] == needle[k]){
    		k ++;
    		j ++;
    		if(needle[j] != needle[k]){
				next[j] = k;
			}else{
				next[j] = next[k];
			}
    	}else{
    		k = next[k];
    	}
    }
    j = 0;
    while(i < lengthHaystack && j < lengthNeedle){
    	if(j == -1 || haystack[i] == needle[j]){
    		i ++;
    		j ++;
    	}else{
    		j = next[j];
    	}
    }
    if(j == lengthNeedle)
    	return i - j;
    else 
    	return -1;
}

int main(){
	char s1[] = {'a','a','b','c','c','\0'};
	char s2[] = {'a','b','c','\0'};
	cout<<strStr(s1, s2)<<endl;
	return 0;
}