#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int actualSum = n * (n + 1) / 2;
        return (actualSum - sum);
    }
};
// Time -> O(N)
// Space -> O(1)