    #include <iostream>
    #include <vector>

    using namespace std;

    // Idea: The problem is to search for a target value in a sorted but rotated array.

    // Approach: The approach is to perform a binary search with some modifications. 
    // If the middle element is the target, we return its index. 
    // If the first element is less than or equal to the middle element, 
    // it means the left half is sorted. So, if the target is within the range of the first element and the middle element, 
    // we perform binary search on the left half, otherwise we perform binary search on the right half. 
    // If the first element is greater than the middle element, it means the right half is sorted. 
    // So, if the target is within the range of the middle element and the last element, 
    // we perform binary search on the right half, otherwise we perform binary search on the left half.

    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int m = l + (r-l)/2;

            if(nums[m] == target){
                return m;
            }
            else if(nums[l] <= nums[m]){
                if(nums[l] <= target && target< nums[m]){
                    r = m-1;
                }else{
                    l = m+1;
                }
            }
            else{
                if(nums[m] < target && target <= nums[r]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }

        return -1;
    }

    // Time Complexity: The time complexity is O(log n), 
    // where n is the size of the array. 
    // This is because we are performing a binary search, which has a time complexity of O(log n).