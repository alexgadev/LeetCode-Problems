#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target){
        std::unordered_map<int, int> umap;
        
        // using a hashmap enables O(n) search
        for(auto i = 0; i < nums.size(); i++){
            if(auto search = umap.find(target - nums[i]); search != umap.end()){
                return {search->second, i};
            }
            umap.insert({nums[i], i});
        }
        return {};
    }
};

int main(){
    Solution sol = Solution();

    std::vector<int> nums = {-3,4,3,90};
    std::vector<int> result = sol.twoSum(nums, 0);

    std::cout << "[";
    for(int i = 0; i < result.size(); i++){
        if(i + 1 == result.size()){
            std::cout << std::to_string(result[i]);
        }
        else{
            std::cout << std::to_string(result[i]) << ",";
        }
    }
    std::cout << "]" << std::endl;
}