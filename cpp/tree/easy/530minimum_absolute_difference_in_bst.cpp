/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (55.36%)
 * Likes:    1362
 * Dislikes: 95
 * Total Accepted:    119.5K
 * Total Submissions: 215.8K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * Given the root of a Binary Search Tree (BST), return the minimum absolute
 * difference between the values of any two different nodes in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [4,2,6,1,3]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,0,48,null,null,12,49]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^4].
 * 0 <= Node.val <= 10^5
 *
 *
 *
 * Note: This question is the same as 783:
 * https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
// Inorder traversing of BST is ascending, so the minimum absolute difference
// must be between two consecutive numbers.
class Solution {
 public:
  int getMinimumDifference(TreeNode* root) {
    dfs(root);
    return res_;
  }

 private:
  int res_ = INT_MAX;
  TreeNode* pre_ = nullptr;

  void dfs(TreeNode* root) {
    if (!root) return;

    dfs(root->left);
    if (pre_) res_ = min(root->val - pre_->val, res_);
    pre_ = root;
    dfs(root->right);
  }
};
// @lc code=end
