#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Use cycle sort to place positive elements smaller than n
        // at the correct index
        int i = 0;
        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }

        // Iterate through nums
        // return smallest missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all elements are at the correct index
        // the smallest missing positive number is n + 1
        return n + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n+1, false);
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] > 0) {
                seen[nums[i]] = true;
            }
        }

        // Check if missing no. is in range [1, n]
        for (int i = 1 ; i <= n ; i++) {
            if (!seen[i]) {
                return i;
            }
        }
        
        return n + 1;
    }
};
// Time -> O(N)
// Space -> O(N)