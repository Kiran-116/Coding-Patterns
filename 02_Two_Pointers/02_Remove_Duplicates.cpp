// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// Brute Force -> Set Data Structure: O(N logN) -> Set Insert, O(N)
// Optimal -> 2 Pointer:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 1;

        while (j < n) {
            if (nums[i] != nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }

        return i+1;
    }
};
// Time -> O(N)
// Space -> O(1);