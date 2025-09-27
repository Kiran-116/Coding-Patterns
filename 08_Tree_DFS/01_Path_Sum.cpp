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
    bool DFS(TreeNode *root, int sum, int target) {
        sum += root -> val;
        if (!root -> left && !root -> right) {
            if (sum == target) {
                return true;
            }
            return false;
        }
        bool left = false, right = false;
        if (root -> left) {
            left = DFS(root -> left, sum, target);
        }
        if (root -> right) {
            right = DFS(root -> right, sum, target);
        }
        return (left || right);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return DFS(root, 0, targetSum);
    }
};
// Time -> O(N)
// Space -> O(N)