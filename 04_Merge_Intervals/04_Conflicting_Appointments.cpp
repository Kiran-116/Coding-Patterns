//  https://www.geeksforgeeks.org/dsa/given-n-appointments-find-conflicting-appointments
#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>, pair<int,int>>> findConflicts(vector<pair<int,int>>& appointments) {
    // Sort intervals by start time
    sort(appointments.begin(), appointments.end());

    vector<pair<pair<int,int>, pair<int,int>>> conflicts;

    for (int i = 1; i < (int)appointments.size(); i++) {
        // If current starts before previous ends => conflict
        if (appointments[i].first < appointments[i-1].second) {
            conflicts.push_back({appointments[i-1], appointments[i]});
        }
    }

    return conflicts;
}

int main() {
    vector<pair<int,int>> appointments = {{4,5}, {2,3}, {3,6}, {5,7}, {7,8}};
    auto conflicts = findConflicts(appointments);

    for (auto &c : conflicts) {
        cout << "[" << c.first.first << "," << c.first.second << "] and "
             << "[" << c.second.first << "," << c.second.second << "] conflict.\n";
    }

    return 0;
}
