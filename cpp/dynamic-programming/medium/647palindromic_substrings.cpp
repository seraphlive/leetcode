/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.24%)
 * Likes:    3913
 * Dislikes: 134
 * Total Accepted:    260.6K
 * Total Submissions: 418.9K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            // find odd length substrings
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
                ++cnt;
            }
            // find even length substrings
            if (i + 1 < n) {
                left = i;
                right = i + 1;
                while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
                ++cnt;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

