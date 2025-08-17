// https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long countTriplets(int n, long long target, long long arr[]) {
        // Your code goes here
        sort(arr, arr + n);
        long long count = 0;
        for (int i = 0 ; i < n-2 ; i++) {
            int j = i+1;
            int k = n-1;
            while (j < k) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                if (sum < target) {
                    count += (k - j);
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return count;
    }
};
// Time -> O(N^2) + O(N logN)
// Space -> O(1)