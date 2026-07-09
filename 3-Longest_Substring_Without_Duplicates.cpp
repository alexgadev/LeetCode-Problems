#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // first version O(n^2), beats 7.23%
        //int max = 0;
        //for(int i = 0; i < s.size(); i++){
        //    int size = 1;
        //    string current = "";
        //    current += s[i];
        //    for(int j = i + 1; j < s.size(); j++){
        //        if(current.find(s[j]) == std::string::npos){
        //            current += s[j];
        //            size++;
        //        }
        //        else{
        //            break;
        //        }
        //    }
        //    if(size > max) max = size;
        //}
        
        //return max;


        int left = 0; int maxLength = 0;
        unordered_set<char> charSet;
        for(int right = 0; right < s.size(); right++){
            while(charSet.find(s[right]) != charSet.end()){
                charSet.erase(s[left++]);
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main(){
    Solution sol = Solution();

    std::cout << sol.lengthOfLongestSubstring("bbbbb") << std::endl;
}