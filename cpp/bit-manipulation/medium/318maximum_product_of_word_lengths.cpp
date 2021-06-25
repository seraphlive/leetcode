/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 *
 * https://leetcode.com/problems/maximum-product-of-word-lengths/description/
 *
 * algorithms
 * Medium (55.36%)
 * Likes:    1352
 * Dislikes: 86
 * Total Accepted:    129K
 * Total Submissions: 233K
 * Testcase Example:  '["abcw","baz","foo","bar","xtfn","abcdef"]'
 *
 * Given a string array words, return the maximum value of length(word[i]) *
 * length(word[j]) where the two words do not share common letters. If no such
 * two words exist, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
 * Output: 16
 * Explanation: The two words can be "abcw", "xtfn".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
 * Output: 4
 * Explanation: The two words can be "ab", "cd".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["a","aa","aaa","aaaa"]
 * Output: 0
 * Explanation: No such pair of words.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists only of lowercase English letters.
 *
 *
 */

// @lc code=start
// Use a int number with its each bits to represent if each letter is used.
class Solution {
 public:
  int maxProduct(vector<string>& w) {
    int n = w.size();
    vector<int> st(n);
    for (int i = 0; i < n; ++i) {
      for (auto c : w[i]) st[i] |= 1 << (c - 'a');
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((st[i] & st[j]) == 0)
          res = max(res, (int)(w[i].size() * w[j].size()));
      }
    }
    return res;
  }
};
// @lc code=end
