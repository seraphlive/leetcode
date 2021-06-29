/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (67.22%)
 * Likes:    5037
 * Dislikes: 220
 * Total Accepted:    1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
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
 * Output: [2,1]
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
// Iterative. For each sub-tree, go down bottom left. After backing to the root,
// check right sub-tree if it exists
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    auto p = root;

    while (p || !st.empty()) {
      while (p) {
        st.push(p);
        p = p->left;
      }
      auto t = st.top();
      st.pop();
      res.push_back(t->val);
      p = t->right;
    }
    return res;
  }
};
// @lc code=end

// DFS
// class Solution {
//  public:
//   vector<int> inorderTraversal(TreeNode* root) {
//     dfs(root);
//     return res_;
//   }

//  private:
//   vector<int> res_;
//   void dfs(TreeNode* root) {
//     if (!root) return;
//     dfs(root->left);
//     res_.push_back(root->val);
//     dfs(root->right);
//   }
// };
