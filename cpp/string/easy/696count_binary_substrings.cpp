/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 *
 * https://leetcode.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (58.45%)
 * Likes:    1340
 * Dislikes: 220
 * Total Accepted:    60.7K
 * Total Submissions: 103.8K
 * Testcase Example:  '"00110"'
 *
 * Give a string s, count the number of non-empty (contiguous) substrings that
 * have the same number of 0's and 1's, and all the 0's and all the 1's in
 * these substrings are grouped consecutively. 
 * 
 * Substrings that occur multiple times are counted the number of times they
 * occur.
 * 
 * Example 1:
 * 
 * Input: "00110011"
 * Output: 6
 * Explanation: There are 6 substrings that have equal number of consecutive
 * 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
 * Notice that some of these substrings repeat and are counted the number of
 * times they occur.
 * Also, "00110011" is not a valid substring because all the 0's (and 1's) are
 * not grouped together.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "10101"
 * Output: 4
 * Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal
 * number of consecutive 1's and 0's.
 * 
 * 
 * 
 * Note:
 * s.length will be between 1 and 50,000.
 * s will only consist of "0" or "1" characters.
 * 
 */

// @lc code=start
// count 1/0 in consecutive groups, e.g. 0110001111->[1,2,3,4]
// For adjacent group, the count of substrings will be min{cnt1, cnt2};
// O(n), O(1).
class Solution {
public:
  int countBinarySubstrings(string s) {
    int cur = 1, pre = 0, res = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++cur;
      } else {
        res += min(cur, pre);
        pre = cur;
        cur = 1;
      }
    }
    return res + min(cur, pre);
  }
};
// @lc code=end

