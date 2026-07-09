#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size % 2 == 0){
            if(size > nums1.size()){

            }
            else if(size == nums1.size()){

            }
            else{

            }
        }
        else{
            return (size / 2) >= nums1.size() ? static_cast<double>(nums2[(size / 2) % nums1.size()]) : static_cast<double>(nums1[size / 2]);
        }
    }
};

int main(){
    Solution sol = Solution();

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}