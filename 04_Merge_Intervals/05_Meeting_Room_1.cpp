// https://www.geeksforgeeks.org/problems/attend-all-meetings/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Code Here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        if (n == 1) {
            return true;
        }
        for (int i = 1 ; i < n ; i++) {
            if (arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};
// Time -> O(N)
// Space -> O(1)