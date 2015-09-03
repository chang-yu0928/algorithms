#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > result;
bool check(string s, int start, int end){
    if(start == end){
        return true;
    }
    while(end > start){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void _partition(string s, int n, vector<int> &container){
    if(n == s.size()){
        vector<string> temp;
        temp.push_back(s.substr(0, container[0]+1));
        for(int i = 1;i < container.size();i ++){
            temp.push_back(s.substr(container[i-1]+1, container[i] - container[i-1]));
        }
        result.push_back(temp);
    }
    for(int i = n;i < s.size();i ++){
        if(check(s, n, i)){
            container.push_back(i);
            _partition(s, i+1, container);
            container.pop_back();
        }
    }
}

    vector<vector<string> > partition(string s) {
        if(s.length() == 0){
            return result;
        }
        vector<int> container;
        _partition(s, 0, container);
        return result;
    }

int main(){
	string s("aaba");
	vector<vector<string> > result = partition(s);
	for(int i = 0;i < result.size();i ++){
		for(int j = 0;j < result[i].size();j ++){
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}
}