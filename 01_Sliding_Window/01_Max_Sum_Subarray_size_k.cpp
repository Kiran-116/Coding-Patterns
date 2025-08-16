// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        for (int i = 0 ; i < k ; i++) {
            sum += arr[i];
        }
        int maxi = sum;
        int left = 0, right = k-1;
        right++;
        while (right < n) {
            sum += arr[right];
            sum -= arr[left];
            left++;
            right++;
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};
// Time -> O(N)
// Space -> O(1)