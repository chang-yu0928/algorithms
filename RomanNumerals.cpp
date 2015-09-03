#include <iostream>
#include <string>
using namespace std;
    int romanToInt(string s) {
        int result = 0, len = s.size();
        int romans[128];
        romans['I'] = 1;
        romans['V'] = 5;
        romans['X'] = 10;
        romans['L'] = 50;
        romans['C'] = 100;
        romans['D'] = 500;
        romans['M'] = 1000;
        for(int i = 0;i < len;i ++) {
            if(i < len && romans[s[i]] < romans[s[i+1]]) {
                result -= romans[s[i]];
            } else {
                result += romans[s[i]];
            }
        }
        return result;
    }

int main(){
cout<<romanToInt("VI")<<endl;
return 0;
}