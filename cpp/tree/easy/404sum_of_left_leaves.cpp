/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (52.63%)
 * Likes:    1987
 * Dislikes: 184
 * Total Accepted:    254.6K
 * Total Submissions: 483.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the sum of all left leaves.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 24
 * Explanation: There are two left leaves in the binary tree, with values 9 and
 * 15 respectively.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -1000 <= Node.val <= 1000
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
// DFS
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    if (root->left && !root->left->left && !root->left->right) {
      return root->left->val + sumOfLeftLeaves(root->right);
    } else {
      return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
  }
};
// @lc code=end

// BFS
// class Solution {
//  public:
//   int sumOfLeftLeaves(TreeNode* root) {
//     if (!root) return 0;
//     queue<TreeNode*> q;
//     q.push(root);
//     int res = 0;

//     while (!q.empty()) {
//       int k = q.size();
//       for (int i = 0; i < k; ++i) {
//         auto t = q.front();
//         q.pop();
//         if (t->left && !t->left->left && !t->left->right) res +=
//         t->left->val; if (t->left) q.push(t->left); if (t->right)
//         q.push(t->right);
//       }
//     }
//     return res;
//   }
// };
