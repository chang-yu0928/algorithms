#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string simplifyPath(string path) {
	int i;
	string result;
	stack<string> folders;
	result = path;
	string folderName;
	for(int i = 0;i < result.size();i ++){
		if(result[i] == '/'){
			if(folderName.size() != 0 && folderName != "."){
				if(folderName != ".."){
					folders.push(folderName);
				}else{
					if(folders.size() > 0){
    					folders.pop();
    				}
				}
			}
			folderName.clear();
		}else{
			folderName += result[i];
		}
	}
	if(folderName.size() != 0 && folderName != "."){
		if(folderName != ".."){
			folders.push(folderName);
		}else{
			if(folders.size() > 0){
    			folders.pop();
    		}
		}
	}
	result.clear();
	if(!folders.empty()){
		result = folders.top();
		folders.pop();
		while(!folders.empty()){
			result = folders.top() + "/" + result;
			folders.pop();
		}
	}
	result = "/" + result;
	return result;
}

int main(){
	cout<<simplifyPath("/.")<<endl;
	return 0;
}