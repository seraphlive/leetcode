/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (58.68%)
 * Likes:    2452
 * Dislikes: 91
 * Total Accepted:    666.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 * Example 5:
 *
 *
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
// Iterative using a stack.
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
      auto t = st.top();
      st.pop();
      res.push_back(t->val);
      if (t->right) st.push(t->right);
      if (t->left) st.push(t->left);
    }
    return res;
  }
};
// @lc code=end

// DFS
// class Solution {
//  public:
//   vector<int> preorderTraversal(TreeNode* root) {
//     dfs(root);
//     return res_;
//   }

//  private:
//   vector<int> res_;
//   void dfs(TreeNode* root) {
//     if (!root) return;
//     res_.push_back(root->val);
//     dfs(root->left);
//     dfs(root->right);
//   }
// };
