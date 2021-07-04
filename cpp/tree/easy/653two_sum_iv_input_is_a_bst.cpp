/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
 *
 * https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (56.61%)
 * Likes:    2222
 * Dislikes: 159
 * Total Accepted:    202.5K
 * Total Submissions: 357.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * Given the root of a Binary Search Tree and a target number k, return true if
 * there exist two elements in the BST such that their sum is equal to the
 * given target.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 9
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], k = 28
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,1,3], k = 4
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: root = [2,1,3], k = 1
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: root = [2,1,3], k = 3
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * root is guaranteed to be a valid binary search tree.
 * -10^5 <= k <= 10^5
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
// binary search for each node. O(nh), O(h).
class Solution {
 public:
  bool findTarget(TreeNode* root, int k) { return dfs(root, root, k); }

 private:
  bool dfs(TreeNode* root, TreeNode* cur, int k) {
    if (!cur) return false;
    return search(root, cur, k - cur->val) || dfs(root, cur->left, k) ||
           dfs(root, cur->right, k);
  }

  bool search(TreeNode* root, TreeNode* cur, int v) {
    if (!root) return false;
    return (root->val == v && root != cur) ||
           (root->val < v && search(root->right, cur, v)) ||
           (root->val > v && search(root->left, cur, v));
  }
};

// @lc code=end

// hast table. O(n), O(n);
// class Solution {
//  public:
//   bool findTarget(TreeNode* root, int k) {
//     unordered_set<int> s;
//     return dfs(root, s, k);
//   }

//  private:
//   bool dfs(TreeNode* root, unordered_set<int>& s, int k) {
//     if (!root) return false;
//     if (s.find(k - root->val) != s.end()) return true;
//     s.insert(root->val);
//     return dfs(root->left, s, k) || dfs(root->right, s, k);
//   }
// };

// Use two stack, O(n), O(h)

// Inorder traversing to get a sorted array then use two pointers. O(n), O(n)
// class Solution {
//  public:
//   bool findTarget(TreeNode* root, int k) {
//     dfs(root);
//     int i = 0, j = arr_.size() - 1;
//     while (i < j) {
//       int sum = arr_[i] + arr_[j];
//       if (sum == k) {
//         return true;
//       } else if (sum < k) {
//         ++i;
//       } else {
//         --j;
//       }
//     }
//     return false;
//   }

//  private:
//   vector<int> arr_;
//   void dfs(TreeNode* root) {
//     if (!root) return;
//     dfs(root->left);
//     arr_.push_back(root->val);
//     dfs(root->right);
//   }
// };
