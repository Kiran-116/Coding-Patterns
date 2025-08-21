// https://leetcode.com/problems/backspace-string-compare/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for (char ch: s) {
            if (ch == '#') {
                if (st1.empty()) {
                    continue;
                }
                st1.pop();
            }
            else {
                st1.push(ch);
            }
        }
        for (char ch: t) {
            if (ch == '#') {
                if (st2.empty()) {
                    continue;
                }
                st2.pop();
            }
            else {
                st2.push(ch);
            }
        }

        while (!st1.empty() && !st2.empty()) {
            char a = st1.top();
            char b = st2.top();
            st1.pop();
            st2.pop();

            if (a != b) {
                return false;
            }
        }

        if (st1.empty() && st2.empty()) {
            return true;
        }
        return false;
    }
};
// Time -> O(N)
// Space -> O(2N)