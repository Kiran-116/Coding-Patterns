// https://leetcode.com/problems/longest-repeating-character-replacement/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Generate all the Substrings:
// Total No. of Char to convert = Length - maxFreq.

// Better -> 2 Pointer and Sliding Window:

// Optimal -> 2 Pointer and Sliding Window => No need of updating maxFreq while Trimming:
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxi = 0, maxFreq = 0;
        int hash[26] = {0};
        while (r < n) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            // Trimming down the Invalid Ones:
            int len = r - l + 1;
            if ((r - l + 1) > (maxFreq + k)) {
                hash[s[l] - 'A']--;
                l++;
                maxFreq = 0;
            }

            if ((r - l + 1) <= maxFreq + k) {
                maxi = max(maxi, r - l + 1);
            }
            r++;
        }

        return maxi;
    }
};
// Time -> O(N)
// Space -> O(26)


// Better -> 2 Pointer and Sliding Window:
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int n = s.size();
//         int l = 0, r = 0, maxLen = 0, maxFreq = 0;
//         int hash[26] = {0};

//         while (r < n) {
//             hash[s[r] - 'A']++;
//             maxFreq = max(maxFreq, hash[s[r] - 'A']);
            
//             // Trimming down the Invalid ones:
//             while ((r-l+1) - maxFreq > k) {
//                 hash[s[l] - 'A']--;
//                 l++;
//                 maxFreq = 0;

//                 for (int i = 0 ; i < 25 ; i++) {
//                     maxFreq = max(maxFreq, hash[i]);
//                 }
//             }

//             if ((r-l+1) - maxFreq <= k) {
//                 maxLen = max(maxLen, r-l+1);
//             }
//             r++;
//         }

//         return maxLen;
//     }
// };
// Time -> O((N + N) * 26)
// Space -> O(26)



// Brute -> Generate all the Substrings:
// Total No. of Char to convert = Length - maxFreq.
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int maxLen = 0;
//         int n = s.size();

//         for (int i = 0 ; i < n ; i++) {
//             int hash[26] = {0};
//             int maxFreq = 0;

//             for (int j = i ; j < n ; j++) {
//                 hash[s[j] - 'A']++;
//                 maxFreq = max(maxFreq, hash[s[j] - 'A']);
//                 int changes = (j-i+1) - maxFreq;

//                 if (changes <= k) {
//                     maxLen = max(maxLen, j-i+1);
//                 }
//                 else {
//                     break;
//                 }
//             }
//         }
//         return maxLen;
//     }
// };
// Time -> O(N^2)
// Space -> O(26)
