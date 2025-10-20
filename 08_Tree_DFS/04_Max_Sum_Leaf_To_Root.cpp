// https://www.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// User function Template for C++
// DFS:
class Solution {
private:
    void solve(Node *root, int sum, int &maxi) {
        if (!root) {
            return;
        }
        sum += root -> data;
        if (!root->left && !root->right) {
            maxi = max(maxi, sum);
        }
        solve(root->left, sum, maxi);
        solve(root->right, sum, maxi);
    }
public:
    int maxPathSum(Node* root) {
        int maxi = INT_MIN;
        solve(root, 0, maxi);
        return maxi;
    }
};
// Time -> O(N)
// Space -> O(N)