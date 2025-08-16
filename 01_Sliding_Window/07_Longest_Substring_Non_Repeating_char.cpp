// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Generate all the Substrings: Time -> O(N^3)
// Better -> Time -> O(N^2)
// Optimal: using HashMap:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        vector<int> mp(255, -1);
        int maxi = 0;

        while (right < n) {
            if (mp[s[right]] != -1) {
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            maxi = max(maxi, (right - left + 1));
            right++;
        }
        return maxi;
    }
};
// Time -> O(N)
// Space -> O(256)