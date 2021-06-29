/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 *
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (64.98%)
 * Likes:    1717
 * Dislikes: 184
 * Total Accepted:    160.2K
 * Total Submissions: 246.7K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 *
 * Example 1:
 *
 * Input:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on
 * level 2 is 11. Hence return [3, 14.5, 11].
 *
 *
 *
 * Note:
 *
 * The range of node's value is in the range of 32-bit signed integer.
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
// BFS
class Solution {
 public:
  vector<double> averageOfLevels(TreeNode* root) {
    if (!root) return {};
    vector<double> res;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      long long sum = 0;
      int k = q.size();
      for (int i = 0; i < k; ++i) {
        auto t = q.front();
        q.pop();
        sum += t->val;
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      res.push_back((double)sum / k);
    }
    return res;
  }
};
// @lc code=end

// DFS preorder
// class Solution {
//  public:
//   vector<double> averageOfLevels(TreeNode* root) {
//     if (!root) return {};
//     vector<pair<long long, int>> sum_cnt;
//     vector<double> res;

//     dfs(root, 0, sum_cnt);

//     for (const auto& p : sum_cnt) {
//       res.push_back(static_cast<double>(p.first) / p.second);
//     }
//     return res;
//   }

//  private:
//   void dfs(TreeNode* root, int depth, vector<pair<long long, int>>& sum_cnt)
//   {
//     if (!root) return;
//     if (depth >= sum_cnt.size()) sum_cnt.push_back({0, 0});
//     sum_cnt[depth].first += root->val;
//     ++sum_cnt[depth].second;

//     dfs(root->left, depth + 1, sum_cnt);
//     dfs(root->right, depth + 1, sum_cnt);
//   }
// };
