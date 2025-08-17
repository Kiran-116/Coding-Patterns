// https://leetcode.com/problems/remove-element/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};
// Time -> O(N)
// Space -> O(1)