#include <iostream>
#include <string>
#include <vector>
using namespace std;

string simplifyPath(string path) {
	int prev = 0, len = path.size();
	string result("/");
	vector<string> folders;
	if(path[len - 1] != '/') {
		path += '/';
	}
	for(int i = 1;i < path.size();i ++) {
		if(path[i] == '/') {
			string f = path.substr(prev + 1, i - prev - 1);
			prev = i;
			if(f == "..") {
				if(!folders.empty())
					folders.pop_back();
				continue;
			}
			if(f != "." && (f.size() != 0)) {
				folders.push_back(f);
			}
		}
	}
	for(int i = 0;i < folders.size();i ++) {
		result += folders[i];
		result += "/";
	}
	if(!folders.empty())
		result.erase(result.end()-1);
	return result;
}

int main(){
	cout<<simplifyPath("/a/./b/../../c/")<<endl;
	return 0;
}