#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        if(x == INT32_MIN || x == INT32_MAX) return 0;

        int result = 0;
        
        int factor = 0, temp = abs(x);
        while(temp > 0){
            factor++;
            temp /= 10;
        }

        while(abs(x) > 0){
            if(result >= INT32_MAX || result <= INT32_MIN) return 0;
            if((x % 10) * pow(10, factor - 1) >= INT32_MAX) return 0;
            if((x % 10) * pow(10, factor - 1) <= INT32_MIN) return 0;
            if(result + (x % 10) * pow(10, factor - 1) >= INT32_MAX) return 0;
            if(result + (x % 10) * pow(10, factor - 1) <= INT32_MIN) return 0;

            result += (x % 10) * pow(10, factor - 1);
            factor--;
            x /= 10;
        }
        return result;
    }
};

int main(){
    Solution sol = Solution();

    std::cout << sol.reverse(-2147483648) << std::endl;
}