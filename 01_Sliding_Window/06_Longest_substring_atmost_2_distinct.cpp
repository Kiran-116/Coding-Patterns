// https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxLen = 0;
        while (r < n) {
            mp[s[r]]++;
            while (mp.size() > 2) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};
// Time -> O(N)
// Space -> O(1)
