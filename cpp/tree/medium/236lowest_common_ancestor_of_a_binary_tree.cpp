/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (50.49%)
 * Likes:    6242
 * Dislikes: 211
 * Total Accepted:    687.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 *
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return dfs(root, p, q);
  }

 private:
  TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    // For current (sub)tree to check, if root is p/q, LCA can't be under the
    // root so just return the root as result.
    if (!root || root == p || root == q) return root;

    // else check the left/right subtree to find if p & q are in the same tree
    // or not.
    auto l = dfs(root->left, p, q);
    auto r = dfs(root->right, p, q);

    // if p & q are seperately in left & right subtrees, root is LCA.
    if (l && r) {
      return root;
    } else {
      // else LCA can be in either left or right subtree whose result is not
      // null.
      return l ? l : r;
    }
  }
};
// @lc code=end
