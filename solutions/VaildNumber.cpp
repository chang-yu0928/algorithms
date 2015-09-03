#include <iostream>
using namespace std;

bool isNumber(const char *s) {
         int len = strlen(s);
        if(len == 0){
            return false;
        }
        int countOfPoint = 0;
        int countOfE = 0;
        int flag1 = 0;
        int flag2 = len;
        int flag3 = 0;
        for(int i = 0;i < len;i ++){
            if(s[i] - ' ' == 0){
                flag1 ++;
            }else{
                break;
            }
        }
        for(int i = len - 1;i >= 0;i --){
            if(s[i] - ' ' == 0){
                flag2 --;
            }else{
                break;
            }
        }
        if(flag2 < flag1 + 1)
            return false;
        for(int i = flag1;i < flag2;i ++){
            char temp = s[i];
            if(temp - '-' == 0 && i == flag1){
                continue;
            }
            if(temp - '+' == 0 && i == flag1){
                continue;
            }
            if(countOfPoint > 1){
                return false;
            }
            if(countOfE > 1){
                return false;
            }
            if(temp - 'e' == 0){
                if(i == flag1 || i == flag2 - 1 || s[i-1] - '-' == 0){
                    return false;
                }
                countOfE ++;
                if(s[i - 1] - '.' == 0 && i - 1 == flag1){
                    return false;
                }
                continue;
            }
            if(temp - '.' == 0){
                countOfPoint ++;
                if(countOfE == 1){
                    return false;
                }
                continue;
            }
            if(temp - '-' == 0 || temp - '+' == 0){
                if(s[i-1] - 'e' == 0){
                    continue;
                }else{
                    return false;
                }
            }
            if(temp - '9' > 0 || temp - '0' < 0){
                return false;
            }else{
                flag3 = 1;
            }
            
        }
        if(countOfPoint > 1){
            return false;
        }
        if(countOfE > 1){
            return false;
        }
        if(flag3 == 0){
            return false;
        }
        return true;

    }

int main(){
    cout<<isNumber(" 005047e+6")<<endl;
    return 0;
}