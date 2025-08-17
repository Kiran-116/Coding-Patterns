// https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, product = 1, count = 0;
        if (k <= 1) {
            return 0;
        }
        while (right < n) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};
// Time -> O(N)
// Space -> O(1)