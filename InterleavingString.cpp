#include <iostream>
#include <vector>
#include <string>
using namespace std;
    vector<vector<bool> > flags;
    bool isInterleave(string s1, string s2, string s3) {
        int length1 = s1.size();
        int length2 = s2.size();
        if(length1 == 0 && length2 == 0 && s3.size() == 0){
            return true;
        }
        if(length1 == 0 && length2 == 0 && s3.size() != 0){
            return false;
        }
        if(s3.size() != length1 + length2){
            return false;
        }
        if(length1 == 0){
            for(int i = 0;i < length2;i ++){
                if(s2[i] != s3[i]){
                    return false;
                }
            }
            return true;
        }
        if(length2 == 0){
            for(int i = 0;i < length1;i ++){
                if(s1[i] != s3[i]){
                    return false;
                }
            }
            return true;
        }
        for(int i = 0;i <= length1;i ++){
            vector<bool> temp;
            for(int j = 0;j <= length2;j ++){
                if(i == 0 && j == 0){
                    temp.push_back(true);
                    continue;
                }
                if(i == 0){
                    temp.push_back(temp[j-1] && (s2[j-1] == s3[i+j-1]));
                }else if(j == 0){
                    temp.push_back((flags[i-1][j] && (s1[i-1] == s3[i+j-1])));
                }else{
                    temp.push_back((temp[j-1] && (s2[j-1] == s3[i+j-1])) | (flags[i-1][j] && (s1[i-1] == s3[i+j-1])));
                }
                cout<<"i:"<<i<<"j:"<<j<<"fuck:"<<temp.back()<<endl;
            }
            flags.push_back(temp);
        }
        return flags[length1][length2];
    }
    
    int main(){
        string s1("ab");
        string s2("aa");
        string s3("abaa");
        cout<<isInterleave(s1,s2,s3)<<endl;
        return 0;
    }