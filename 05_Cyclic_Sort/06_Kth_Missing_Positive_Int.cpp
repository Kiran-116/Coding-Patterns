// https://leetcode.com/problems/kth-missing-positive-number/
// !!! IMP => Binary Search Approach:
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0, high = n-1;

        while (low <= high) {
            int mid = low + (high - low)/2;
            
            int missingNos = arr[mid] - (mid+1);

            if (missingNos < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

       // Actual + k
       return (high + 1) + k; 
    }
};
// O(log N)
// O(1)