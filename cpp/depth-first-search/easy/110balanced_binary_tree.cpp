/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (45.18%)
 * Likes:    3766
 * Dislikes: 240
 * Total Accepted:    589.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as:
 *
 *
 * a binary tree in which the left and right subtrees of every node differ in
 * height by no more than 1.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,3,3,null,null,4,4]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -10^4 <= Node.val <= 10^4
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
// Single pass. Do the checking while calculating the height.
class Solution {
 public:
  bool isBalanced(TreeNode* root) { return dfs(root) != -1; }

 private:
  int dfs(TreeNode* root) {
    if (!root) return 0;

    int l = dfs(root->left);
    if (l == -1) return -1;
    int r = dfs(root->right);
    if (r == -1) return -1;

    if (abs(l - r) > 1) return -1;
    return max(l, r) + 1;
  }
};
// @lc code=end

// Reuse maxDepth. Find depth first then compare, which is 2 passes.
// class Solution {
//  public:
//   bool isBalanced(TreeNode* root) {
//     if (!root) return true;

//     int l = maxDepth(root->left);
//     int r = maxDepth(root->right);
//     return abs(l - r) <= 1 && isBalanced(root->left) &&
//     isBalanced(root->right);
//   }

//  private:
//   int maxDepth(TreeNode* root) {
//     if (!root) return 0;
//     return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//   }
// };
