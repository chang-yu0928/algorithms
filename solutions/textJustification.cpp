#include <iostream>
#include <string>
#include <vector>

using namespace std;

string justify(vector<string> &words, int maxWidth, int width) {
		if(words.size() == 1) {
			string dummy(maxWidth - words[0].size(), ' ');
            dummy = words[0] + dummy;
            return dummy;
		}
        int len = words.size() - 1, spaceNum = maxWidth - width + len + 1;
        int left = spaceNum % len, num = spaceNum / len, i = 0;
        string spaces1((num + 1), ' '), spaces2(num, ' '), res;
        for(i = 0;i < left;i ++) {
            res += (words[i] + spaces1);
        }
        for(;i < len;i ++) {
            res += (words[i] + spaces2);
        }
        res += (words[i]);
        if(res.size() < maxWidth) res += spaces2;
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> dummy, result;
        int width = 0;
        for(int i = 0;i < words.size();i ++) {
            width += (words[i].size() + 1);
            if(width - 1 > maxWidth) {
                width -= (words[i].size() + 1);
                result.push_back(justify(dummy, maxWidth, width));
                dummy.clear();
                width = words[i].size() + 1;
            }
            dummy.push_back(words[i]);
        }
        if(!dummy.empty()) {
            string temp;
            for(int i = 0;i < dummy.size() - 1;i ++) {
                temp += (dummy[i] + " ");
            }
            temp += dummy[dummy.size() - 1];
            if(temp.size() < maxWidth) {
                string dummy(maxWidth - temp.size(), ' ');
                temp += dummy;
            }
            result.push_back(temp);
        }
        return result;
    }
    
    int main() {
    	string a[] = {"justification.", "This", "is", "an", "example", "of", "text"};
    	vector<string> words(a, a + 7);
    	vector<string> non;
    	vector<string> res = fullJustify(non, 16);
    	for(int i = 0;i < res.size();i ++) {
    		cout<<res[i]<<endl;
    	}
    	return 0;
    	
    }