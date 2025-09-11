#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> employeeFreeTime(vector<vector<int>> &schedule) {
    sort(schedule.begin(), schedule.end());
    vector<vector<int>> merged;
    for (const auto &interval : schedule) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    vector<vector<int>> freeTime;
    for (int i = 1; i < merged.size(); i++) {
        if (merged[i][0] > merged[i - 1][1]) {
            freeTime.push_back({merged[i - 1][1], merged[i][0]});
        }
    }
    return freeTime;
}
int main()
{
    vector<vector<int>> schedule = {{1, 3}, {9, 12}, {2, 4}, {6, 8}};
    vector<vector<int>> result = employeeFreeTime(schedule);
    for (const auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]"  << " ";
    }
    return 0;
}