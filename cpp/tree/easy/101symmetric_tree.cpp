/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (49.13%)
 * Likes:    6524
 * Dislikes: 171
 * Total Accepted:    926.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
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
// BFS
class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    if (!root->left || !root->right) return root->left == root->right;
    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
      auto l = q.front();
      q.pop();
      auto r = q.front();
      q.pop();
      if (l->val != r->val) return false;

      if (!l->left || !r->right) {
        if (l->left != r->right) return false;
      } else {
        q.push(l->left);
        q.push(r->right);
      }

      if (!l->right || !r->left) {
        if (l->right != r->left) return false;
      } else {
        q.push(l->right);
        q.push(r->left);
      }
    }
    return true;
  }
};
// @lc code=end

// DFS
// class Solution {
//  public:
//   bool isSymmetric(TreeNode* root) {
//     if (!root) return true;
//     return dfs(root->left, root->right);
//   }

//  private:
//   bool dfs(TreeNode* l, TreeNode* r) {
//     if (!l || !r) return l == r;
//     if (l->val != r->val) return false;
//     return dfs(l->left, r->right) && dfs(l->right, r->left);
//   }
// };
