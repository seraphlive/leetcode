/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (43.12%)
 * Likes:    3377
 * Dislikes: 636
 * Total Accepted:    642.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return true if the
 * tree has a root-to-leaf path such that adding up all the values along the
 * path equals targetSum.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], targetSum = 0
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int ts) {
    if (!root) return false;
    if (!root->left && !root->right && root->val == ts) return true;
    return hasPathSum(root->left, ts - root->val) ||
           hasPathSum(root->right, ts - root->val);
  }
};
// @lc code=end
