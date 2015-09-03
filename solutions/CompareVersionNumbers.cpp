#include <iostream>
#include <string>
#include <vector>
using namespace std;
int compareVersion(string version1, string version2);

int main(){
	string temp1("1.1");
	string temp2("1");
	cout << compareVersion(temp1,temp2)<<endl;
	return 1;
}
	int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0, len1 = version1.size(), len2 = version2.size(), ind1 = 0, ind2 = 0;
        while(ind1 < len1 && ind2 < len2) {
            while(ind1 < len1 && version1[ind1] != '.') {
                v1 = v1 * 10 + (version1[ind1] - '0');
                ind1 ++;
            }
            while(ind2 < len2 && version2[ind2] != '.') {
                v2 = v2 * 10 + (version2[ind2] - '0');
                ind2 ++;
            }
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            else {
                v1 = 0;
                v2 = 0;
                ind1 ++;
                ind2 ++;
            }
        }
        if(ind1 < len1) {
            while(ind1 < len1 && version1[ind1] != '.') {
                v1 = v1 * 10 + (version1[ind1] - '0');
                ind1 ++;
            }
            if(v1 != 0) return 1;
        }
        if(ind2 < len2) {
            while(ind2 < len2 && version2[ind2] != '.') {
                v2 = v2 * 10 + (version2[ind2] - '0');
                ind2 ++;
            }
            if(v2 != 0) return -1;
        }
        return 0;
    }