/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (59.15%)
 * Likes:    2767
 * Dislikes: 118
 * Total Accepted:    510.1K
 * Total Submissions: 862.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * Output: [2,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree is in the range [0, 100].
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
// Iteration. root->right->left then reverse.
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
      auto t = st.top();
      st.pop();
      res.push_back(t->val);
      if (t->left) st.push(t->left);
      if (t->right) st.push(t->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

// DFS
// class Solution {
//  public:
//   vector<int> postorderTraversal(TreeNode* root) {
//     dfs(root);
//     return res_;
//   }

//  private:
//   vector<int> res_;
//   void dfs(TreeNode* root) {
//     if (!root) return;
//     dfs(root->left);
//     dfs(root->right);
//     res_.push_back(root->val);
//   }
// };
