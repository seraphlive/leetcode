/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (73.62%)
 * Likes:    965
 * Dislikes: 63
 * Total Accepted:    151.8K
 * Total Submissions: 205.2K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given the root of an n-ary tree, return the preorder traversal of its nodes'
 * values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal.
 * Each group of children is separated by the null value (See examples)
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [1,3,5,6,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The height of the n-ary tree is less than or equal to 1000.
 * 
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// DFS
class Solution {
public:
    vector<int> preorder(Node* root)
    {
        if (!root) return {};
        vector<int> res;
        dfs(root, res);
        return res;
    }
private:
    void dfs(Node* root, vector<int>& res)
    {
        if (!root) return;
        res.push_back(root->val);
        for (auto p : root->children) dfs(p, res);
    }
};

// @lc code=end

// BFS
// class Solution {
// public:
//     vector<int> preorder(Node* root)
//     {
//         if (!root) return {};
//         vector<int> res;
//         stack<Node*> st;
//         st.push(root);
//         while (!st.empty()) {
//             auto cur = st.top();
//             st.pop();
//             res.push_back(cur->val);
//             for (int i = cur->children.size() - 1; i >= 0; --i)
//                 st.push(cur->children[i]);
//         }
//         return res;
//     }
// };
