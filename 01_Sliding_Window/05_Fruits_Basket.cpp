// https://leetcode.com/problems/fruit-into-baskets/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int n = fruits.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int maxi = 0;
        while (r < n) {
            mp[fruits[r]]++;
            if (mp.size() > k) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if (mp.size() == k) {
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }
        return maxi;
    }
};
// Time -> O(N)
// Space -> O(N)