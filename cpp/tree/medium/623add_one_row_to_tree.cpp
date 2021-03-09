/*
 * @lc app=leetcode id=623 lang=cpp
 *
 * [623] Add One Row to Tree
 *
 * https://leetcode.com/problems/add-one-row-to-tree/description/
 *
 * algorithms
 * Medium (50.42%)
 * Likes:    583
 * Dislikes: 140
 * Total Accepted:    44.8K
 * Total Submissions: 88.8K
 * Testcase Example:  '[4,2,6,3,1,5]\n1\n2'
 *
 * Given the root of a binary tree, then value v and depth d, you need to add a
 * row of nodes with value v at the given depth d. The root node is at depth
 * 1. 
 * 
 * The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the
 * left subtree of the new left subtree root, its original right subtree should
 * be the right subtree of the new right subtree root. If depth d is 1 that
 * means there is no depth d-1 at all, then create a tree node with value v as
 * the new root of the whole original tree, and the original tree is the new
 * root's left subtree.
 * 
 * Example 1:
 * 
 * Input: 
 * A binary tree as following:
 * ⁠      4
 * ⁠    /   \
 * ⁠   2     6
 * ⁠  / \   / 
 * ⁠ 3   1 5   
 * 
 * v = 1
 * 
 * d = 2
 * 
 * Output: 
 * ⁠      4
 * ⁠     / \
 * ⁠    1   1
 * ⁠   /     \
 * ⁠  2       6
 * ⁠ / \     / 
 * ⁠3   1   5   
 * 
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * A binary tree as following:
 * ⁠     4
 * ⁠    /   
 * ⁠   2    
 * ⁠  / \   
 * ⁠ 3   1    
 * 
 * v = 1
 * 
 * d = 3
 * 
 * Output: 
 * ⁠     4
 * ⁠    /   
 * ⁠   2
 * ⁠  / \    
 * ⁠ 1   1
 * ⁠/     \  
 * 3       1
 * 
 * 
 * 
 * Note:
 * 
 * The given d is in range [1, maximum depth of the given tree + 1].
 * The given binary tree has at least one tree node.
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
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        dfs(root, 1, v, d);
        return root;
    }
private:
    void dfs(TreeNode* root, int depth, int v, int d)
    {
        if (!root) return;
        if (depth < d - 1) {
            dfs(root->left, depth + 1, v, d);
            dfs(root->right, depth + 1, v, d);
        }
        else {
            auto tmp = root->left;
            root->left = new TreeNode(v);
            root->left->left = tmp;
            tmp = root->right;
            root->right = new TreeNode(v);
            root->right->right = tmp;
        }
    }
};
// @lc code=end

// BFS
// class Solution {
// public:
//     TreeNode* addOneRow(TreeNode* root, int v, int d)
//     {
//         if (d == 1) {
//             TreeNode* new_root = new TreeNode(v);
//             new_root->left = root;
//             return new_root;
//         }
//         queue<TreeNode*> q;
//         q.push(root);
//         for (int i = 0; i < d - 2; ++i) {
//             int s = q.size();
//             for (int j = 0; j < s; ++j) {
//                 auto n = q.front();
//                 q.pop();
//                 if (n->left) q.push(n->left);
//                 if (n->right) q.push(n->right);
//             }
//         }
//         while(!q.empty()) {
//             auto n = q.front();
//             q.pop();
//             auto tmp = n->left;
//             n->left = new TreeNode(v);
//             n->left->left = tmp;
//             tmp = n->right;
//             n->right = new TreeNode(v);
//             n->right->right = tmp;
//         }
//         return root;
//     }
// };
