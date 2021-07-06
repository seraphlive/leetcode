/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (54.25%)
 * Likes:    694
 * Dislikes: 96
 * Total Accepted:    53.9K
 * Total Submissions: 99.3K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n' +
  '[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * Implement the MapSum class:
 *
 *
 * MapSum() Initializes the MapSum object.
 * void insert(String key, int val) Inserts the key-val pair into the map. If
 * the key already existed, the original key-value pair will be overridden to
 * the new one.
 * int sum(string prefix) Returns the sum of all the pairs' value whose key
 * starts with the prefix.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MapSum", "insert", "sum", "insert", "sum"]
 * [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
 * Output
 * [null, null, 3, null, 5]
 *
 * Explanation
 * MapSum mapSum = new MapSum();
 * mapSum.insert("apple", 3);
 * mapSum.sum("ap");           // return 3 (apple = 3)
 * mapSum.insert("app", 2);
 * mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= key.length, prefix.length <= 50
 * key and prefix consist of only lowercase English letters.
 * 1 <= val <= 1000
 * At most 50 calls will be made to insert and sum.
 *
 *
 */

// @lc code=start
class MapSum {
 public:
  /** Initialize your data structure here. */
  MapSum() : root_{new Node()} {}
  ~MapSum() { delete root_; }

  void insert(string key, int val) {
    auto p = root_;
    for (auto c : key) {
      if (!p->next[c - 'a']) p->next[c - 'a'] = new Node();
      p = p->next[c - 'a'];
    }
    p->val = val;
  }

  int sum(string prefix) {
    auto p = find(prefix);
    if (!p) return 0;
    return dfs(p);
  }

 private:
  static constexpr std::size_t kN_ = 26;
  struct Node {
    int val;
    Node* next[kN_];

    Node() : val(0), next{nullptr} {}
    ~Node() {
      for (auto i : next) {
        if (i) delete i;
      }
    }
  };
  Node* root_;

  Node* find(string word) {
    auto p = root_;
    for (std::size_t i = 0; i < word.size() && p; ++i)
      p = p->next[word[i] - 'a'];
    return p;
  }

  int dfs(Node* root) {
    if (!root) return 0;
    int res = root->val;
    for (auto i : root->next) {
      if (i) res += dfs(i);
    }
    return res;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
