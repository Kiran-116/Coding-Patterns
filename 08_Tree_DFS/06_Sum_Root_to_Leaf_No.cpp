// https://leetcode.com/problems/sum-root-to-leaf-numbers/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void solve(TreeNode *root, string str, vector<int> &ans) {
        if (!root->left && !root->right) {
            str += to_string(root->val);
            ans.push_back(stoi(str));
            return;
        }
        if (root -> left) {
            solve(root -> left, str + to_string(root -> val), ans);
        }
        if (root -> right) {
            solve(root -> right, str + to_string(root -> val), ans);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        solve(root, "", ans);
        // Sum:
        int sum = 0;
        for (auto it: ans) {
            cout << it << " " << endl;
            sum += it;
        }
        return sum;
    }
};
// Time -> O(N)
// Space -> O(N)