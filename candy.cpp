#include <iostream>
#include <vector>

using namespace std;

	int candy(vector<int>& ratings) {
        int length = ratings.size();
        vector<int> result(length, 1);
        if(length == 0) {
            return 0;
        }
        if(length == 1) {
            return 1;
        }
        int count = 0;
    	for(int i = 1;i < length;i ++) {
    		if(ratings[i] > ratings[i-1]) {
    			result[i] = result[i-1] + 1;
    		}
    	}
    	for(int i = length - 2;i >= 0;i --) {
    		if(ratings[i] > ratings[i + 1]) {
    			result[i] = max(result[i+1] + 1, result[i]);
    		}
    	}
    	for(int i = 0;i < result.size();i ++) {
    		cout<<result[i]<<" ";
    	    count += result[i];
    	}
    	cout<<endl;
    	return count;
    }

int main() {
	vector<int> ratings;
	ratings.push_back(2);
	ratings.push_back(2);
	
	int result = candy(ratings);
	cout<<result<<endl;
	return 0;
}