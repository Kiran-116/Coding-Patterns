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
public:
    int maxLevelSum(TreeNode* root) {
        int maxi = INT_MIN;
        int maxiLevel = 0;
        if (!root) {
            return maxiLevel;
        }

        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            for (int i = 0 ; i < size ; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node -> val;
                if (node -> left) {
                    q.push(node -> left);
                }
                if (node -> right) {
                    q.push(node -> right);
                }
            }
            if (sum > maxi) {
                maxi = sum;
                maxiLevel = level;
            }
            level++;
        }
        return maxiLevel;
    }
};
// Time -> O(N)
// Space -> O(N)