// https://leetcode.com/problems/circular-array-loop/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> adj;
    vector<int> color;

    bool DFS(int node) {
        color[node] = 0; // visiting (gray)

        for (auto it: adj[node]) {
            if (color[it] == 1) { // white → explore
                if (DFS(it)) return true;
            } else if (color[it] == 0) { 
                // found a back edge → cycle
                return true;
            }
        }

        color[node] = 2; // done (black)
        return false;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        adj.assign(n, {});
        color.assign(n, 1); // all white

        for (int i = 0; i < n; i++) {
            int j = (i + nums[i]) % n;
            if (j < 0) j += n; // handle negative modulo

            if (i == j) continue; // skip self-loop

            // only add edge if same direction
            if ((nums[i] > 0 && nums[j] > 0) || (nums[i] < 0 && nums[j] < 0)) {
                adj[i].push_back(j);
            }
        }

        for (int i = 0; i < n; i++) {
            if (color[i] == 1 && DFS(i)) {
                return true;
            }
        }
        return false;
    }
};
// Time -> O(N ^ 2)
// Space -> O(N)