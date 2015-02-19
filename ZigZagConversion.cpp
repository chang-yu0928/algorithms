#include <iostream>
#include <string>
using namespace std;
string convert(string s, int nRows) {
        int length = s.size();
        string result;
        if(length == 0 || nRows == 0){
            return result;
        }
        if(nRows%2 != 0){
            for(int i = 0;i < nRows;i ++){
                if(i != nRows/2){
                    int k = 0;
                    while((i + k * (nRows+1)) < length){
                        result += s[i + k * (nRows+1)];
                        k ++;
                    }
                }else{
                    int step = nRows - nRows/2;
                    int k = 0;
                    while((i + k * step) < length){
                        result += s[i + k * step];
                        k++;
                    }
                }
            }
        }else{
            for(int i = 0;i < nRows;i ++){
                int k = 0;
                while((i + k * nRows) < length){
                    result += s[i + k * nRows];
                    k ++;
                }
            }
        }
        return result;
    }
    
int main(){
    string s("ABC");
    cout<<convert(s, 2)<<endl;
    return 0;
}