/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.63%)
 * Likes:    5427
 * Dislikes: 325
 * Total Accepted:    278.6K
 * Total Submissions: 572.8K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 *
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
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
// DFS with hash-table to memorize prefix sum and count of valid paths to get
// the prefix sum.
class Solution {
 public:
  int pathSum(TreeNode* root, int ts) {
    unordered_map<int, int> ht;
    ht[0] = 1;
    int cnt = 0;
    dfs(root, 0, ts, cnt, ht);
    return cnt;
  }

 private:
  void dfs(TreeNode* root, int cur, int ts, int& cnt,
           unordered_map<int, int>& ht) {
    if (!root) return;
    cur += root->val;
    if (ht.find(cur - ts) != ht.end()) cnt += ht[cur - ts];
    ++ht[cur];
    dfs(root->left, cur, ts, cnt, ht);
    dfs(root->right, cur, ts, cnt, ht);
    --ht[cur];  // backtracking.
  }
};
// @lc code=end

// Brute-force dfs.
// class Solution {
//  public:
//   int pathSum(TreeNode* root, int ts) {
//     if (!root) return 0;
//     int cnt =
//         dfs(root, ts) + pathSum(root->left, ts) + pathSum(root->right, ts);
//     return cnt;
//   }

//  private:
//   int dfs(TreeNode* root, int ts) {
//     if (!root) return 0;
//     int res = 0;
//     if (root->val == ts) ++res;
//     res += dfs(root->left, ts - root->val) + dfs(root->right, ts -
//     root->val); return res;
//   }
// };
