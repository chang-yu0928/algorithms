#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int evalRPN(vector<string> &tokens) {
    if(tokens.empty()){
        return 0;
    }
    stack<int> temp;
    for(int i = 0;i < tokens.size();i ++){
        if(tokens[i] == "+"){
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();
            int tempResult = x + y;
            temp.push(tempResult);
        }else if(tokens[i] == "-"){
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();
            int tempResult = y - x;
            temp.push(tempResult);
        }else if(tokens[i] == "*"){
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();
            int tempResult = x * y;
            temp.push(tempResult);
        }else if(tokens[i] == "/"){
            int x = temp.top();
            temp.pop();
            int y = temp.top();
            temp.pop();
            int tempResult = y / x;
            temp.push(tempResult);
        }else{
            int x = atoi(tokens[i].c_str());
            temp.push(x);
        }
    }
    return temp.top();
}
    
int main(){
    vector<string> tokens;
    tokens.push_back("0");
    tokens.push_back("3");
    tokens.push_back("/");
    cout<<evalRPN(tokens)<<endl;
}