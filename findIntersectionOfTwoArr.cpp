    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    // Idea: The problem is to find the intersection of two arrays. 
    // That is, we need to find all the elements that are common to both arrays.

    // Approach: The approach is to sort both arrays and then use two pointers to find common elements. 
    // If the elements at the current pointers are equal, we add it to the result. 
    // If the element in the first array is smaller, we move the pointer in the first array forward, 
    // and if the element in the second array is smaller, we move the pointer in the second array forward.

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;

        int i=0, j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                if(res.empty() || res.back() != nums1[i]){
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return res;
    }

    int main() {
        vector<int> nums1 = {1, 2, 2, 1};
        vector<int> nums2 = {2, 2};
        vector<int> result = intersection(nums1, nums2);
        for(int i : result) {
            cout << i << " ";
        }
        return 0;
    }

    // Time Complexity: The time complexity is O(n log n + m log m), 
    // where n and m are the sizes of the two input arrays. 
    // This is because we are sorting both arrays, and then performing a linear scan.