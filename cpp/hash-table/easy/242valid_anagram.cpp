/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (59.30%)
 * Likes:    2773
 * Dislikes: 166
 * Total Accepted:    850.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */

// @lc code=start
// Hash-table, O(n), O(26).
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> cnt(26);

    for (int i = 0; i < s.size(); ++i) {
      ++cnt[s[i] - 'a'];
      --cnt[t[i] - 'a'];
    }
    for (int i : cnt) {
      if (i) return false;
    }
    return true;
  }
};
// @lc code=end

// Sorting, O(nlogn), O(1).
// class Solution {
// public:
//   bool isAnagram(string s, string t) {
//     if (s.size() != t.size()) return false;

//     sort(s.begin(), s.end());
//     sort(t.begin(), t.end());
//     return s == t;
//   }
// };
