#include <iostream>
#include <string>
#include <vector>
using namespace std;
int compareVersion(string version1, string version2);

int main(){
	string temp1("1.0");
	string temp2("1");
	cout << compareVersion(temp1,temp2)<<endl;
	return 1;
}
	int compareVersion(string version1, string version2) {
        vector<int> v1container;
        vector<int> v2container;
        string buffer;
        for(int i = 0;i < version1.length();i ++){
        	if(version1[i] != '.'){
        		buffer += version1[i];
        	}else{
        		v1container.push_back(atoi(buffer.c_str()));
        		buffer.clear();
        	}
        }
        v1container.push_back(atoi(buffer.c_str()));
        buffer.clear();
        for(int i = 0;i < version2.length();i ++){
        	if(version2[i] != '.'){
        		buffer += version2[i];
        	}else{
        		v2container.push_back(atoi(buffer.c_str()));
        		buffer.clear();
        	}
        }
        v2container.push_back(atoi(buffer.c_str()));
        int length = v1container.size() > v2container.size() ? v2container.size() : v1container.size();
        // cout<<"length"<<length<<endl;
        // cout<<"v1container"<<v1container[1]<<endl;
        // cout<<"v2container"<<v2container[1]<<endl;
        for(int i = 0;i < length;i ++){
        	if(v1container[i] > v2container[i]){
        		return 1;
        	}else if(v1container[i] < v2container[i]){
        		return -1;
        	}
        }
        if(v1container.size() > v2container.size()){
        	for(int i = length;i < v1container.size();i ++){
        		if(v1container[i] != 0){
        			return 1;
        		}
        	}
        	return 0;
        }else if(v1container.size() < v2container.size()){
        	for(int i = length;i < v2container.size();i ++){
        		if(v2container[i] != 0){
        			return -1;
        		}
        	}
        	return 0;
        }else{
        	return 0;
        }
    }