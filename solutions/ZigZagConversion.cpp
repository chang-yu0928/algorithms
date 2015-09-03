#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string convert(string s, int numRows) {
        stringstream result;
        int step = 2 * numRows - 2, len = s.size(), step1, step2, index;
        if(step == 0) return s;
        index = 0;
        while(index < len) {
            result << s[index];
            index += step;
        }
        for(int i = 1;i < numRows - 1;i ++) {
            step1 = step - 2 * i;
            step2 = i * 2;
            index = i;
            while(index < len) {
                result << s[index];
                index += step1;
                if(index < len) result << s[index];
                index += step2;
            }
        }
        index = numRows - 1;
        while(index < len) {
            result << s[index];
            index += step;
        }
        return result.str();
    }
    
int main(){
    string s("PAYPALISHIRING");
    cout<<convert(s, 3)<<endl;
    return 0;
}