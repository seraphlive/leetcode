/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 *
 * https://leetcode.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (84.23%)
 * Likes:    1171
 * Dislikes: 56
 * Total Accepted:    90K
 * Total Submissions: 106.2K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * Given the root of a binary tree, return the sum of values of its deepest
 * leaves.
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * Output: 15
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * Output: 19
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * 1 <= Node.val <= 100
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// DFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int depth)
    {
        if (!root) return;
        if (!root->left && !root->right) {
            if (depth == deepest) sum += root->val;
            else if (depth > deepest) {
                sum = root->val;
                deepest = depth;
            }
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
private:
    int deepest = 0;
    int sum = 0;
};
// @lc code=end

// BFS
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            res = 0;
            int cnt = q.size();
            while (cnt--) {
                auto node = q.front();
                q.pop();
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }
        return res;
    }
};
