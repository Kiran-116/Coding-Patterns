// https://leetcode.com/problems/maximum-average-subarray-i/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = k-1, n = nums.size();
        long long sum = 0;
        for (int i = 0 ; i <= right ; i++) {
            sum += nums[i];
        }
        double maxi = sum / (double)k;
        right++;
        while (right < n) {
            sum -= nums[left];
            sum += nums[right];
            left++;
            right++;
            double val = sum / (double)k;
            maxi = max(maxi, val);
        }
        return maxi;   
    }
};
// Time -> O(N)
// Space -> O(1)