// https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (auto it: intervals) {
            if (ans.empty() || ans.back()[1] < it[0]) {
                ans.push_back(it);
            }
            else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        return ans;
    }
};
// Time -> O(N)
// Space -> O(1)