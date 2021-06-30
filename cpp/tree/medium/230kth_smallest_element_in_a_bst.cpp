/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (63.78%)
 * Likes:    4174
 * Dislikes: 90
 * Total Accepted:    562.3K
 * Total Submissions: 881.4K
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * (1-indexed) smallest element in the tree.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 *
 *
 *
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
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
// Follow up: similar with B+ tree. Maintain a dubly-linked list to optimize the
// query. Insert/delete operations are still O(H) and query will be O(k).
// Iterative.
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    int cnt = 0;
    int res;
    auto p = root;
    while (p || !st.empty()) {
      while (p) {
        st.push(p);
        p = p->left;
      }
      auto t = st.top();
      st.pop();
      ++cnt;
      if (cnt == k) {
        res = t->val;
        break;
      }
      p = t->right;
    }
    return res;
  }
};
// @lc code=end

// DFS
// class Solution {
//  public:
//   int kthSmallest(TreeNode* root, int k) {
//     dfs(root, k);
//     return val_;
//   }

//  private:
//   int val_ = 0;
//   int cnt_ = 0;

//   void dfs(TreeNode* root, int k) {
//     if (!root) return;

//     dfs(root->left, k);

//     ++cnt_;
//     if (cnt_ == k) {
//       val_ = root->val;
//       return;
//     }
//     dfs(root->right, k);
//   }
// };
