/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (40.86%)
 * Likes:    2152
 * Dislikes: 488
 * Total Accepted:    371.8K
 * Total Submissions: 909.9K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 * 
 * 
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 * 
 * 
 */

// @lc code=start
// ascii size is 256. Use two ht to map char from s & t to same number, in case
// of wrong mapping or duplicate mapping. (record their last appear position)
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int ht1[256] = {0}, ht2[256] = {0};
    for (int i = 0; i < s.size(); ++i) {
      if (ht1[s[i]] != ht2[t[i]]) return false;
      ht1[s[i]] = i + 1;
      ht2[t[i]] = i + 1;
    }
    return true;
  }
};
// @lc code=end

