#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define MAXNUM 10;

struct compare {
    bool operator()(const pair<int, FILE *> p1, const pair<int, FILE *> p2) {
        return (p1.first > p2.first);
    }
};
/* read the numbers from file char by char */
void outerSort(string file_name) {
    FILE *fp = fopen(file_name.c_str(), "r"), *out;
    string ss;
    int fileCount = 0;
    vector<int> sortBuff;
    if(fp == NULL) {
        cout<<"File doesn't exist"<<endl;
        return;
    }
    char c = getc(fp);
    while(c != EOF) {
        if(c == ' ') {
            if(!ss.empty()) sortBuff.push_back(atoi(ss.c_str()));
            ss.clear();
        } else {
            ss += c;
        }
        if(sortBuff.size() == 10) {
            sort(sortBuff.begin(), sortBuff.end()) ;
            string tempFileName = "temp/part" + to_string(fileCount);
            out = fopen(tempFileName.c_str(), "w");
            if(out == NULL) {
                cout<<"cannot create temp files"<<endl;
                exit(1);
            }
            for(int i = 0;i < sortBuff.size();i ++) {
                fprintf(out, "%d ", sortBuff[i]);
            }
            fclose(out);
            fileCount ++;
            sortBuff.clear();
        }
        c = getc(fp);
    }
    if(!ss.empty()) sortBuff.push_back(atoi(ss.c_str()));
    if(!sortBuff.empty()) {
        sort(sortBuff.begin(), sortBuff.end());
        string tempFileName = "temp/part" + to_string(fileCount);
        out = fopen(tempFileName.c_str(), "w");
        if(out == NULL) {
            cout<<"cannot create temp files"<<endl;
            exit(1);
        }
        for(int i = 0;i < sortBuff.size();i ++) {
            fprintf(out, "%d ", sortBuff[i]);
        }
        fclose(out);
        fileCount ++;
    }
    fclose(fp);

/* merge sort all temp files using heap*/
    out = fopen("result", "w");
    vector<FILE *> tempFiles(fileCount);
    priority_queue<pair<int, FILE *>, vector<pair<int, FILE *> >, compare> que;
    for(int i = 0;i < fileCount;i ++) {
        string tempFileName = "temp/part" + to_string(i);
        tempFiles[i] = fopen(tempFileName.c_str(), "r");
    }
    for(int i = 0;i < fileCount;i ++) {
        char c = getc(tempFiles[i]);
        string num;
        while(c != EOF && c != ' ') {
            num += c;
            c = getc(tempFiles[i]);
        }
        if(!num.empty()) que.push(make_pair(atoi(num.c_str()), tempFiles[i]));
    }
    while(!que.empty()) {
        pair<int, FILE *> p = que.top();
        que.pop();
        fprintf(out, "%d ", p.first);
        char c = getc(p.second);
        string num;
        while(c != EOF && c != ' ') {
            num += c;
            c = getc(p.second);
        }
        if(!num.empty()) que.push(make_pair(atoi(num.c_str()), p.second));
    }
    fclose(out);
}

int main() {
    outerSort("input");
    return 0;
}
