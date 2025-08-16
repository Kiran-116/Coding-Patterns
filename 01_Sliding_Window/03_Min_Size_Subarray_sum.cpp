// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int mini = INT_MAX;
        while (right < n) {
            sum += nums[right];
            while (sum >= target) {
                mini = min(mini, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return mini == INT_MAX ? 0 : mini;
    }
};
// Time -> O(N)
// Space -> O(1)