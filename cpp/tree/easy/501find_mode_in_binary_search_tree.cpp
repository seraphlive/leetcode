/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (44.57%)
 * Likes:    1472
 * Dislikes: 431
 * Total Accepted:    115.8K
 * Total Submissions: 259.8K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given the root of a binary search tree (BST) with duplicates, return all the
 * mode(s) (i.e., the most frequently occurred element) in it.
 *
 * If the tree has more than one mode, return them in any order.
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
// Two pass to get the size of modes for real O(1) space.
class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    dfs(root);
    return res_;
  }

 private:
  vector<int> res_;
  int cnt_ = 1;
  int max_ = 1;
  TreeNode* pre_ = nullptr;

  void dfs(TreeNode* root) {
    if (!root) return;
    dfs(root->left);

    if (pre_) {
      if (pre_->val == root->val) {
        ++cnt_;
      } else {
        cnt_ = 1;
      }
    }
    if (cnt_ > max_) {
      max_ = cnt_;
      res_.clear();
      res_.push_back(root->val);
    } else if (cnt_ == max_) {
      res_.push_back(root->val);
    }
    pre_ = root;

    dfs(root->right);
  }
};
// @lc code=end
