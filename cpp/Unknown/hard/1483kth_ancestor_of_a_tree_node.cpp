/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 *
 * https://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
 *
 * algorithms
 * Hard (32.86%)
 * Likes:    532
 * Dislikes: 60
 * Total Accepted:    13.6K
 * Total Submissions: 41.4K
 * Testcase Example:  '["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]\n' +
  '[[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]'
 *
 * You are given a tree with n nodes numbered from 0 to n-1 in the form of a
 * parent array where parent[i] is the parent of node i. The root of the tree
 * is node 0.
 * 
 * Implement the function getKthAncestor(int node, int k) to return the k-th
 * ancestor of the given node. If there is no such ancestor, return -1.
 * 
 * The k-th ancestor of a tree node is the k-th node in the path from that node
 * to the root.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * ["TreeAncestor","getKthAncestor","getKthAncestor","getKthAncestor"]
 * [[7,[-1,0,0,1,1,2,2]],[3,1],[5,2],[6,3]]
 * 
 * Output:
 * [null,1,0,-1]
 * 
 * Explanation:
 * TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
 * 
 * treeAncestor.getKthAncestor(3, 1);  // returns 1 which is the parent of 3
 * treeAncestor.getKthAncestor(5, 2);  // returns 0 which is the grandparent of
 * 5
 * treeAncestor.getKthAncestor(6, 3);  // returns -1 because there is no such
 * ancestor
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= n <= 5*10^4
 * parent[0] == -1 indicating that 0 is the root node.
 * 0 <= parent[i] < n for all 0 < i < n
 * 0 <= node < n
 * There will be at most 5*10^4 queries.
 * 
 */

// @lc code=start
// Binary lifting
class TreeAncestor {
  vector<vector<int>> up; // int up[N][20];
  vector<int> depth;
  int _log;
public:
  TreeAncestor(int n, vector<int>& parent) {
    _log = 0;
    while ((1 << _log) <= n) ++_log;
    up = vector<vector<int>>(n, vector<int>(_log));
    depth = vector<int>(n);
    // up[v][j] denotes the node after we go up 2^j-th steps from v
    parent[0] = 0;
    for (int v = 0; v < n; ++v) {
      up[v][0] = parent[v];
      if (v != 0) depth[v] = depth[parent[v]] + 1;
      for (int j = 1; j < _log; ++j) {
        up[v][j] = up[up[v][j - 1]][j - 1];
      }
    }
  }

  int getKthAncestor(int node, int k) {
    if (depth[node] < k) return -1;
    for (int j = 0; j < _log; ++j) {
      if (k >> j & 1) node = up[node][j];
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

