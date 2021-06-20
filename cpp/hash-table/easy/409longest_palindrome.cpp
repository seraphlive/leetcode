/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.42%)
 * Likes:    1659
 * Dislikes: 106
 * Total Accepted:    206.2K
 * Total Submissions: 393.5K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 * 
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a"
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "bb"
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2000
 * s consists of lowercase and/or uppercase English letters only.
 * 
 * 
 */

// @lc code=start
// count freq of each letter. letter with even cnt can all be used and each letter
// with odd count must be left one, except for only one of them that can be used.
// O(52n), O(1).
class Solution {
public:
  int longestPalindrome(string s) {
    int odds = 0;
    for (char c = 'A'; c <= 'z'; ++c) {
      odds += count(s.begin(), s.end(), c) % 2;
    }
    return s.size() - odds + (odds > 0);
  }
};
// @lc code=end

// Use hashtable to count freq. // O(52 + n), O(52)
// class Solution {
// public:
//   int longestPalindrome(string s) {
//     unordered_map<int, int> cnt;
//     for (int i = 0; i < s.size(); ++i) {
//       if (s[i] <= 'Z') {
//         ++cnt[s[i] - 'A'];
//       } else {
//         ++cnt[s[i] - 'a' + 26];
//       }
//     }

//     int res = 0;
//     bool is_odd = false;
//     for (int i = 0; i < cnt.size(); ++i) {
//       res += cnt[i];
//       if (cnt[i] % 2) {
//         is_odd = true;
//         --res;
//       }
//     }
//     if (is_odd) ++res;
//     return res;
//   }
// };
