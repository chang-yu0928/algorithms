#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

string changeToInt(string s);
vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<long, int> container;
        vector<string> result;
        int length = s.size();
        if(length < 10){
            return result;
        }
        string temp = changeToInt(s);
        string sub = temp.substr(0, 10);
        long start = stol(sub, nullptr, 10);
        container[start] = 1;
        for(int i = 10;i < length;i ++){
        	cout<<start<<endl;
        	long cut = 1000000000*(temp[i-10] - '0');
            start -= 1000000000*(temp[i-10] - '0');
            start *= 10;
            start += temp[i] - '0';
            cout<<start<<endl;
            if(container.find(start) == container.end()){
                container[start] = 1;
            }else if(container[start] == 1){
                result.push_back(s.substr(i-9, 10));
                container[start] ++;
            }
        }
        return result;
    }
    
    //change string s to string "int" s.
    string changeToInt(string s){
    	string result(s.size(),'0');
        for(int i = 0;i < s.size();i ++){
            switch(s[i]){
                case 'A':{result[i] = '1'; break;}
                case 'C':{result[i] = '2'; break;}
                case 'G':{result[i] = '3'; break;}
                case 'T':{result[i] = '4'; break;}
                default: exit(-1);
            }
        }
        return result;
    }
    
int main(){
	vector<string> result = findRepeatedDnaSequences("GAGAGAGAGAGA");
	for(int i = 0;i < result.size();i ++){
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}