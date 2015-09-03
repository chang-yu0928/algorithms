#include <iostream>
#include <vector>

using namespace std;

int expandSquare(vector<vector<char> > &matrix, int x, int y) {
        int length = 1;
        bool isSquare = true;
        while(true) {
            if(x + length >= matrix.size() || y + length >= matrix[x].size()) {
                break;
            }
            for(int i = 0;i < length;i ++) {
                if(i == length - 1) {
                    if(matrix[x+i][y+length] != '1' || matrix[x+length][y+i] != '1' || matrix[x+length][y+length] != '1') {
                        isSquare = false;
                    }
                } else {
                    if(matrix[x+i][y+length] != '1' || matrix[x+length][y+i] != '1') {
                        isSquare = false;
                    }
                }
            }
            if(!isSquare) {
                break;
            }
            length ++;
        }
        for(int i = x;i < x + length;i ++) {
            for(int j = y;j < y + length;j ++) {
                matrix[i][j] = 0;
            }
        }
        return length * length;
    }
    int maximalSquare(vector<vector<char> >& matrix) {
        int max = 0;
        for(int i = 0;i < matrix.size();i ++) {
            for(int j = 0;j < matrix[i].size();j ++) {
                if(matrix[i][j] == '1') {
                    int size = expandSquare(matrix, i, j);
                    if(size > max) {
                        max = size;
                    }
                }
            }
        }
        
        return max;
    }
    
    
    int main() {
    	vector<vector<char> > input(4, vector<char>(5));
    	input[0][0] = '0';input[0][1] = '0';input[0][2] = '1';input[0][3] = '0';input[0][4] = '0';
    	input[1][0] = '1';input[1][1] = '0';input[1][2] = '1';input[1][3] = '1';input[1][4] = '1';
    	input[2][0] = '1';input[2][1] = '1';input[2][2] = '1';input[2][3] = '1';input[2][4] = '1';
    	input[3][0] = '1';input[3][1] = '0';input[3][2] = '0';input[3][3] = '1';input[3][4] = '0';
    	
   		cout<<maximalSquare(input)<<endl;
   		return 0;
    }