// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.size();
        map<char, int> mp;
        int l = 0, r = 0, maxLen = -1;
        while (r < n) {
            mp[s[r]]++;
            if (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }
                l++;
            }
            if (mp.size() == k) {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        
        return maxLen;
    }
};
// Time -> O(N)
// Space -> O(1)
