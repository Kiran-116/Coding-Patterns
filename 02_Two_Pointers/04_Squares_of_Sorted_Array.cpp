// https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Radix Sort -> O(N), O(N)
// Better -> Sort Function:
// Optimal -> 2 Pointer:
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        vector<int> ans(n);

        for (int i = n-1 ; i >= 0 ; i--) {
            if (abs(nums[start]) >= abs(nums[end])) {
                ans[i] = nums[start] * nums[start];
                start++;
            }
            else {
                ans[i] = nums[end] * nums[end];
                end--;
            }
        }

        return ans;
    }
};
// Time -> O(N)
// Space -> O(N)