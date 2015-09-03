#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> dict;
    vector<int> result;
    int size = words[0].size();
    int length = words.size() * words[0].size();
    if(s.size() < length) {
        return result;
    }
    for(int i = 0;i < words.size();i ++) {
        dict[words[i]] ++;
    }
    for(int k = 0;k < size;k ++) {
    	int i = k, start = i;
    	while(i + size <= s.size()) {
    		string sub = s.substr(i, size);
    		if(dict.find(sub) != dict.end()) {
    			if(dict[sub] != 0) {
    				dict[sub] --;
    				i += size;
    				if(i - start == length) {
    					result.push_back(start);
    				}
    			} else {
    				dict[s.substr(start, size)] ++;
    				start += size;
    			}
    		} else {
    			while(start < i) {
    				dict[s.substr(start, size)] ++;
    				start += size;
    			}
    			i += size;
    			start = i;
    		}
    	}
    	while(start < i) {
    		dict[s.substr(start, size)] ++;
    		start += size;
    	}
    }
    return result;
}

int main() {
	vector<string> input;
	input.push_back("word");
	input.push_back("good");
	input.push_back("best");
	input.push_back("good");
	vector<int> output = findSubstring("wordgoodgoodgoodbestword", input);
	for(int i = 0;i < output.size();i ++) {
		cout<<output[i]<<" ";
	}
	cout<<endl;
	return 0;
}