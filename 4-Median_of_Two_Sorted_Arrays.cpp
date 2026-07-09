#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& arr, vector<int>& l, vector<int>& r){
        int left = 0, right = arr.size() - 1;

        int mid = left + (right - left) / 2;

        int i = 0, j = 0;
        int k = left;

        // Merge the vectors into arr[left..right]
        while(i < l.size() && j < r.size()){
            if(l[i] <= r[j]){
                arr[k] = l[i];
                i++;
            }
            else{
                arr[k] = r[j];
                j++;
            }
            k++;
        }

        // copy the remaining elements of l[], if there are any
        while(i < l.size()){
            arr[k] = l[i];
            i++;
            k++;
        }

        // copy the remaining elements of r[], if there are any
        while(j < r.size()){
            arr[k] = r[j];
            j++;
            k++;
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr(nums1.size() + nums2.size());
        merge(arr, nums1, nums2);


        int size = arr.size();

        int index = size / 2;
        if(size % 2 == 0){
            return static_cast<double>((arr[index - 1] + arr[index]) / 2.0);
        }
        else{
            return static_cast<double>(arr[index]);
        }
    }
};

int main(){
    Solution sol = Solution();

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}