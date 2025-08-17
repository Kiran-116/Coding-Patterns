// https://leetcode.com/problems/two-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        unordered_map<int, int> mp;     //  {elem, ind}
        for (int i = 0 ; i < n ; i++) {
            int rem = target - nums[i];
            if (mp.find(rem) != mp.end()) {
                return {mp[rem], i};
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
// Time -> O(N)
// Space -> O(N)