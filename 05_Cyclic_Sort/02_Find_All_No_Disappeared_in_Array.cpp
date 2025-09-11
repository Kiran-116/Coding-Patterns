#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }
        vector<int> ans;
        for (int i = 1 ; i <= n ; i++) {
            if (mp[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Time -> O(N)
// Space -> O(N logN)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> arr(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(arr.find(i) == arr.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Time -> O(N)
// Space -> O(N)