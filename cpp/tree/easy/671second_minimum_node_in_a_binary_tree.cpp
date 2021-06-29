/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (42.92%)
 * Likes:    879
 * Dislikes: 1147
 * Total Accepted:    106.8K
 * Total Submissions: 248.8K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. More formally, the property root.val
 * = min(root.left.val, root.right.val) always holds.
 *
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 *
 * If no such second minimum value exists, output -1 instead.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [2,2,5,null,null,5,7]
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,2,2]
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 25].
 * 1 <= Node.val <= 2^31 - 1
 * root.val == min(root.left.val, root.right.val) for each internal node of the
 * tree.
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
// Value k of the root is the smallest. The function return the first value that
// is bigger than k. For each node check it's children. If the child's value
// equals to k, recursively go down that pass until the first value that doesn't
// equal to k is found.
class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (!root) return -1;
    if (!root->left && !root->right)
      return -1;  // Root either has no child or two children.

    int lv = root->left->val;
    int rv = root->right->val;
    if (lv == root->val) lv = findSecondMinimumValue(root->left);
    if (rv == root->val) rv = findSecondMinimumValue(root->right);
    if (lv != -1 && rv != -1) return min(lv, rv);
    if (lv != -1) return lv;
    return rv;
  }
};
// @lc code=end

// Use set to remove duplate number.
// class Solution {
//  public:
//   int findSecondMinimumValue(TreeNode* root) {
//     dfs(root);
//     if (s.size() >= 2) return *next(s.begin(), 1);
//     return -1;
//   }

//  private:
//   set<int> s;
//   void dfs(TreeNode* root) {
//     if (!root) return;
//     s.insert(root->val);
//     dfs(root->left);
//     dfs(root->right);
//   }
// };
