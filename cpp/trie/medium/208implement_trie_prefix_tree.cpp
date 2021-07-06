/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    4828
 * Dislikes: 72
 * Total Accepted:    433.4K
 * Total Submissions: 807.6K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() : root_{new Node()} {}

  ~Trie() { delete root_; }

  /** Inserts a word into the trie. */
  void insert(string word) {
    auto p = root_;
    for (auto c : word) {
      if (!p->next[c - 'a']) p->next[c - 'a'] = new Node();
      p = p->next[c - 'a'];
    }
    p->tag = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    auto p = find(word);
    return p && p->tag;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    auto p = find(prefix);
    return p;
  }

 private:
  static constexpr std::size_t kN_ = 26;
  struct Node {
    bool tag;
    Node* next[kN_];

    Node() : tag(false), next{nullptr} {}
    ~Node() {
      for (auto i : next) {
        if (i) delete i;
      }
    }
  };
  Node* root_;

  Node* find(const string& word) {
    auto p = root_;
    for (std::size_t i = 0; i < word.size() && p; ++i)
      p = p->next[word[i] - 'a'];
    return p;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
