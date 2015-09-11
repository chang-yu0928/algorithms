#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for(int i = 0;i < rowIndex;i ++) {
        	int temp1 = row[0], temp2;
            for(int j = 0;j < row.size() - 1;j ++) {
            	temp2 = row[j+1];
                row[j+1] = temp1 + row[j+1];
                temp1 = temp2;
            }
            row.push_back(1);
        }
        return row;
    }
    
    int main() {
    	vector<int> res = getRow(2);
    	for(int i = 0;i < res.size();i ++) {
    		cout<<res[i]<<" ";
    	}
    	cout<<endl;
    }