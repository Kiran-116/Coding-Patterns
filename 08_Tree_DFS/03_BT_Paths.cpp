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
    void findPath(TreeNode* node, vector<string>& ans, string temp) {
        temp += to_string(node->val); 
        if (node->left) findPath(node->left, ans, temp + "->"); 
        if (node->right) findPath(node->right, ans, temp + "->"); 
        if (!node->left && !node->right) ans.push_back(temp); 
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root) findPath(root, ans, ""); 
        return ans;
    }
};
// Time -> O(N)
// Space -> O(N)