#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int n=v.size();
        vector<int>ans;

        sort(v.begin(),v.end());
        
        for(int i = 0 ; i < n-1 ; i++) {
            if(v[i] == v[i+1]) {
                ans.push_back(v[i]);
                i++;
            }
        }

        return ans;
    }
};
// Time -> O(N logN) + O(N)
// Space -> O(1)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
// Time -> O(N)
// Space -> O(N)