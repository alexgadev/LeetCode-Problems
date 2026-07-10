#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows == s.length()) return s;

        int index = 0, distance = 1;
        vector<vector<char>> map(numRows);
        for(char c : s){
            map[index].push_back(c);
            if(index == 0){
                distance = 1;
            }
            else{
                if(index == numRows - 1){
                    distance = -1;
                }
            }
            index += distance;
        }

        string result = "";
        for(const auto& row : map){
            for(char ch : row){
                result += ch;
            }
        }
        
        return result;
    }
};

int main(){
    Solution sol = Solution();

    std::cout << sol.convert("PAYPALISHIRING", 2) << std::endl;
}