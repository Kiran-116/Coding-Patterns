#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int actualSum = n * (n + 1) / 2;
        return (sum - actualSum);
    }
};
// Time -> O(N)
// Space -> O(1)