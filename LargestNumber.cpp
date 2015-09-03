#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


bool compare(string s1, string s2) {
    	string temp1 = s1 + s2;
    	string temp2 = s2 + s1;
    	if(temp1 >= temp2){
    		return true;
    	}
    	return false;
    }
    
    string intToString(int num){
    	stringstream temp;
    	temp << num;
    	return temp.str();
    }
    
    string largestNumber(vector<int> &num) {
        vector<string> container(num.size());
        string result;
        int flag = 0;
        for(int i = 0;i < num.size();i ++){
        	flag += num[i];
        	container[i] = intToString(num[i]);
        }
        if(flag == 0){
        	return "0";
        }
        sort(container.begin(), container.end(), compare);
        for(int i = 0;i < container.size();i ++){
        	result += container[i];
        }
        return result;
    }

int main(){
	vector<int> input;
	input.push_back(0);
	input.push_back(0);
	input.push_back(0);
	input.push_back(0);
	input.push_back(9);
	cout<<largestNumber(input)<<endl;
	return 0;
}