#include <iostream>
#include <string>
using namespace std;

void reverse(string &sentence, int start, int end) {
    int len = end - start + 1;
    for(int i = 0;i < len/2;i ++) {
        swap(sentence[i+start], sentence[end - i]);
    }
}
void reverseWords(string &sentence) {
    int i = 0, start = 0, len = sentence.size();
    while(i < len) {
        if(sentence[i] == ' ' || sentence[i] == ',' || sentence[i] == '.'){
            reverse(sentence, start, i - 1);
            start = i + 1;
        }
        i ++;
    }
}

int main() {
	string input("I am    ABC, but CDE.");
	reverseWords(input);
	cout<<input<<endl;
	return 0;
}