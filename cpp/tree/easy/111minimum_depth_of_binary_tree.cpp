/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (40.42%)
 * Likes:    2613
 * Dislikes: 841
 * Total Accepted:    580K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^5].
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
// BFS. Because BFS traverse the tree in level order, we get the minimal depth
// the first time we visit a leaf.
class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> q;
    int res = 0;
    q.push(root);

    while (!q.empty()) {
      ++res;             // count current level.
      int k = q.size();  // size of queue is changing.
      for (int i = 0; i < k; ++i) {
        auto t = q.front();
        q.pop();
        if (!t->left && !t->right) return res;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
    }
    return -1;
  }
};
// @lc code=end

// DFS.
// class Solution {
//  public:
//   int minDepth(TreeNode* root) {
//     if (!root) return 0;
//     int l = minDepth(root->left);
//     int r = minDepth(root->right);
//     if (!l || !r) return l + r + 1;
//     return min(l, r) + 1;
//   }
// };
