// https://leetcode.com/problems/happy-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>mp;

        while (true) {
            int sum = 0;
            while (n != 0) {
                int digit = n % 10;
                sum += (digit * digit);
                n /= 10;
            }

            if (sum == 1) {
                return true;
            }
            if (mp.find(sum) != mp.end()) {
                return false;
            }
            mp.insert(sum);
            n = sum;
        }
        return false;
    }
};
// Time -> O(log N)
// Space -> O(log N)