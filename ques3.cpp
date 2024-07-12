#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == NULL) return 0;

        // Recursively get the maximum path sum of the left and right subtrees
        int left = max(0, maxPathSumHelper(node->left, maxSum));
        int right = max(0, maxPathSumHelper(node->right, maxSum));

        // Update maxSum if the maximum path sum passing through the current node is greater
        int currentSum = node->val + left + right;
        maxSum = max(maxSum, currentSum);

        // Return the maximum path sum with the current node as the end node
        return node->val + max(left, right);
    }
};
int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Maximum path sum: " << solution.maxPathSum(root) << endl;

    return 0;
}
