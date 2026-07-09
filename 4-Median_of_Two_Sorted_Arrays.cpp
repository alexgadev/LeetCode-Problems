#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // O(m + n + log(m) + log(n))
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

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        
        if(N1 < N2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = N2 * 2;

        while(lo <= hi){
            // indices
            int mid2 = lo + hi / 2; // nums2 middle guess cut
            int mid1 = N1 + N2 - mid2; // nums1 middle guess cut
            
            // calculate lower and upper halves (values)
            double L1 = (mid1 == 0) ? DBL_MIN : nums1[(mid1 - 1) / 2];
            double L2 = (mid2 == 0) ? DBL_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? DBL_MAX : nums1[mid1 / 2];
            double R2 = (mid2 == N2 * 2) ? DBL_MAX : nums2[mid2 / 2];

            if(L1 > R1) lo = mid2 + 1; // moves middle cuts pos to the left (nums1) and pos to the right (nums2)
            else if(L2 > R2) hi = mid2 - 1; // moves middle cuts to the right (nums1) and pos to the right (nums2)
            else return ((max(L1, L2) + min(R1, R2)) / 2); // right cuts
        }

        return -1.0;
    }
};

int main(){
    Solution sol = Solution();

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    std::cout << sol.findMedianSortedArrays(nums1, nums2) << std::endl;
}