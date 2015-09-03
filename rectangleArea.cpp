#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int coverArea = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        int areaA = (C - A) * (D - B);
        int areaB = (G - E) * (H - F);
        if((E <= C && A <= G && B <= H && F <= D)) {
            return areaA + areaB - coverArea;
        } else {
            return areaA + areaB;
        }
    }
    
    int main() {
    	cout<<computeArea(-5,4,0,5,-3,-3,3,3)<<endl;
    	return 0;
    }