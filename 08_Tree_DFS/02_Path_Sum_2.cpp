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
    void solve(TreeNode *root, int target, vector<vector<int>> &ans, vector<int> &path) {
        if (!root) {
            return;
        }
        if (!root -> left && !root -> right) {
            path.push_back(root -> val);
            if (target == root -> val) {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }

        path.push_back(root -> val);
        solve(root -> left, target - root -> val, ans, path);
        solve(root -> right, target - root -> val, ans, path);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, ans, path);
        return ans;
    }
};
// Time -> O(N)
// Space -> O(N)