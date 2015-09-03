#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDecodings(string s) {
        if(s.size() == 0){
            return 0;
        }
        vector<int> result;
        for(int i = 0;i < s.size();i ++){
            if(i == 0){
                if(s[i] == '0'){
                    result.push_back(0);
                }else{
                    result.push_back(1);
                }
                continue;
            }
            if(s[i] == '0'){
            	cout<<"OK"<<endl;
                if(s[i-1] <= '2' && s[i-1] > '0'){
                    result.push_back(result[i-1]);
                    cout<<result[i-1]<<endl;
                }else{
                    result.push_back(0);
                }
            }else if(s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6')){
                int temp = 0;
                if(i-2 >= 0){
                    temp = result[i-1] + result[i-2];
                }else{
                    temp = result[i-1] + 1;
                }
                result.push_back(temp);
            }else{
                int temp = result[i-1];
                result.push_back(temp);
            }
        }
        return result[s.size()-1];
    }
    
int main(){
	string s("100");
	cout<<numDecodings(s)<<endl;
	return 0;
}