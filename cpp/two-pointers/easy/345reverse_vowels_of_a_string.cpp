/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (45.68%)
 * Likes:    1130
 * Dislikes: 1551
 * Total Accepted:    290.5K
 * Total Submissions: 635.9K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    if (s.empty()) return NULL;

    int i = 0, j = s.size() - 1;
    while (i < j) {
      i = s.find_first_of("aeiouAEIOU", i);
      j = s.find_last_of("aeiouAEIOU", j);
      if (i < j) swap(s[i++], s[j--]);
    }
    return s;
  }
};
// @lc code=end
