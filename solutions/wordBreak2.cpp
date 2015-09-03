#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

void wordBreak(string s, unordered_set<string>& wordDict, vector<string> &result, int start, string part, int maxLength) {
        if(start == s.size()) {
            result.push_back(part);
            return;
        }
        for(int i = start;i < start + maxLength && i < s.size();i ++) {
            string sub = s.substr(start, i - start + 1);
	        if(wordDict.find(sub) != wordDict.end()) {
	        	string temp;
	            if(part.size() == 0) {
	            	temp = sub;
	            } else {
                	temp = part + " " + sub;
                }
                wordBreak(s, wordDict, result, i + 1, temp, maxLength);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        if(s.size() == 0) {
            return result;
        }
        int maxLength = 0;
        for(string word : wordDict) {
            if(maxLength < word.size()) {
                maxLength = word.size();
            }
        }
        string part;
        wordBreak(s, wordDict, result, 0, part, maxLength);
        return result;
    }
    
    int main() {
    	unordered_set<string> wordDict;
    	wordDict.insert("cat");wordDict.insert("cats");wordDict.insert("and");wordDict.insert("sand");wordDict.insert("dog");
    	vector<string> result = wordBreak("catsanddog", wordDict);
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	}
    	cout<<endl;
    	return 0;
    }