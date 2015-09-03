#include <iostream>
#include <string>
#include <vector>
using namespace std;

void restore(string s, int start, vector<string> &result, int level){
        if(start >= s.size()){
            return;
        }
        if(level == 4){
        	int len = s.size() - start;
            string temp = s.substr(start, len);
            int num = atoi(temp.c_str());
            if(len > 3 || num > 255 || (len > 1 && temp[0] == '0')){
                return;
            }
            result.push_back(s);
        }else{
            for(int i = 1;i <= 3;i ++){
            	if(start + i < s.size()){
	                string temp = s.substr(start, i);
	                int num = atoi(temp.c_str());
	                if(num <= 255 && (i == 1 || (i > 1 && temp[0] != '0'))){
	                    string nextTemp = s;
	                    nextTemp.insert(start+i, ".");
	                    restore(nextTemp, start+i+1, result, level+1);
	                }
	            }
            }
        }
    }


    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restore(s, 0, result, 1);
        return result;
    }
    
int main(){
	vector<string> result = restoreIpAddresses("2736786374048");
	for(int i = 0;i < result.size();i ++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}