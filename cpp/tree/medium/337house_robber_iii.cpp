/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
 *
 * https://leetcode.com/problems/house-robber-iii/description/
 *
 * algorithms
 * Medium (52.12%)
 * Likes:    4296
 * Dislikes: 69
 * Total Accepted:    217.9K
 * Total Submissions: 418.1K
 * Testcase Example:  '[3,2,3,null,3,null,1]'
 *
 * The thief has found himself a new place for his thievery again. There is
 * only one entrance to this area, called root.
 *
 * Besides the root, each house has one and only one parent house. After a
 * tour, the smart thief realized that all houses in this place form a binary
 * tree. It will automatically contact the police if two directly-linked houses
 * were broken into on the same night.
 *
 * Given the root of the binary tree, return the maximum amount of money the
 * thief can rob without alerting the police.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,2,3,null,3,null,1]
 * Output: 7
 * Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,4,5,1,3,null,1]
 * Output: 9
 * Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * 0 <= Node.val <= 10^4
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
// DFS with memoization
class Solution {
 public:
  int rob(TreeNode* root) {
    if (!root) return 0;
    if (ht.find(root) != ht.end())
      return ht[root];  // Return directly if calculated.

    // Depending on choose current node or not...
    // Choose current node, then choose its grandsons.
    int a1 = root->val;
    if (root->left) a1 += rob(root->left->left) + rob(root->left->right);
    if (root->right) a1 += rob(root->right->left) + rob(root->right->right);

    // Don't choose current node, then choose its sons.
    int a2 = rob(root->left) + rob(root->right);

    int res = max(a1, a2);
    ht[root] = res;
    return res;
  }

 private:
  unordered_map<TreeNode*, int> ht;
};
// @lc code=end
