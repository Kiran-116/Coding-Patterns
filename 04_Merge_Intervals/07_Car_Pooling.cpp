// https://leetcode.com/problems/car-pooling/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> time(1001, 0);
        for (const auto& trip : trips) {
            time[trip[1]] += trip[0];
            time[trip[2]] -= trip[0];
        }
        int currentPassengers = 0;
        for (int i = 0; i < 1001; i++) {
            currentPassengers += time[i];
            if (currentPassengers > capacity) return false;
        }
        return true;
    }
};
// Time -> O(N)
// Space -> O(1)