#include <string>
#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        bool negative = false, started = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '-' || s[i] == '+'){
                if(!started){
                    started = true;
                    if(s[i] == '-') negative = true;
                }
                else{
                    return negative ? result * (-1) : result;
                }
            }
            else{
                if(s[i] >= '0' && s[i] <= '9'){
                    if(!started) started = true;
                    if(result > 0xCCCCCCC){
                        return negative ? INT32_MIN : INT32_MAX;
                    }
                    else{
                        if(result == 0xCCCCCCC && s[i] > '7' && s[i] <= '9'){
                            return negative ? INT32_MIN : INT32_MAX;
                        }
                        std::cout << s[i] - '0' << std::endl;
                        result = result == 0 ? s[i] - '0' : (result * 10) + (s[i] - '0');
                    }
                }
                else{
                    if(s[i] != ' '){
                        return negative ? result * (-1) : result;
                    }
                    else{
                        if(started) return negative ? result * (-1) : result;
                    }
                }
            }
        }
        return negative ? result * (-1) : result;
    }
};

int main(){
    Solution sol = Solution();

    std::cout << sol.myAtoi("-5-") << std::endl;
}