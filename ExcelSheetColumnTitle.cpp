#include <iostream>
#include <string>
#include <stack>
using namespace std;
    string convertToTitle(int n) {
        stack<int> container;

        string result;
      	while(n > 26)
        {
        	cout<<n<<endl;
            container.push(n % 26);
            n = n / 26;
        }
        container.push(n % 26);

        while(container.size() != 0){
            int temp = container.top();
            cout << temp <<endl;
            container.pop();
            switch(temp){
                case 1: result += "A"; break;
                case 2: result += "B"; break;
                case 3: result += "C"; break;
                case 4: result += "D"; break;
                case 5: result += "E"; break;
                case 6: result += "F"; break;
                case 7: result += "G"; break;
                case 8: result += "H"; break;
                case 9: result += "I"; break;
                case 10: result += "J"; break;
                case 11: result += "K"; break;
                case 12: result += "L"; break;
                case 13: result += "M"; break;
                case 14: result += "N"; break;
                case 15: result += "O"; break;
                case 16: result += "P"; break;
                case 17: result += "Q"; break;
                case 18: result += "R"; break;
                case 19: result += "S"; break;
                case 20: result += "T"; break;
                case 21: result += "U"; break;
                case 22: result += "V"; break;
                case 23: result += "W"; break;
                case 24: result += "X"; break;
                case 25: result += "Y"; break;
                case 0: result += "Z"; break;
            }
        }
        return result;
    }

int main(){
	string temp = convertToTitle(27);
	cout << temp << endl;
	return 0;
}