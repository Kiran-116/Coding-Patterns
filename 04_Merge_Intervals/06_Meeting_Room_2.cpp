// Given a list of intervals representing the start and endTime ofN meetings, 
// find the minimum number of rooms required to hold all the meetings.

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Create a vector of start and end times
        vector<pair<int, int>> times;
        for (const auto& interval : intervals) {
            times.emplace_back(interval[0], 1);  // Start time
            times.emplace_back(interval[1], -1); // End time
        }

        // Sort the times
        sort(times.begin(), times.end());

        int maxRooms = 0, currentRooms = 0;
        for (const auto& time : times) {
            currentRooms += time.second;
            maxRooms = max(maxRooms, currentRooms);
        }

        return maxRooms;
    }
};
// Time -> O(N log N)
// Space -> O(N)

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << sol.minMeetingRooms(intervals) << endl; // Output: 2
    return 0;
}