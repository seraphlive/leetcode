/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 *
 * https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/
 *
 * algorithms
 * Easy (43.79%)
 * Likes:    22
 * Dislikes: 2
 * Total Accepted:    5.5K
 * Total Submissions: 12.7K
 * Testcase Example:  '"bank"\n"kanb"'
 *
 * You are given two strings s1 and s2 of equal length. A string swap is an
 * operation where you choose two indices in a string (not necessarily
 * different) and swap the characters at these indices.
 * 
 * Return true if it is possible to make both strings equal by performing at
 * most one string swap on exactly one of the strings. Otherwise, return
 * false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "bank", s2 = "kanb"
 * Output: true
 * Explanation: For example, swap the first character with the last character
 * of s2 to make "bank".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "attack", s2 = "defend"
 * Output: false
 * Explanation: It is impossible to make them equal with one string swap.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s1 = "kelb", s2 = "kelb"
 * Output: true
 * Explanation: The two strings are already equal, so no string swap operation
 * is required.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s1 = "abcd", s2 = "dcba"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 100
 * s1.length == s2.length
 * s1 and s2 consist of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<array<char, 2>> map;
        for (int i = 0; i < s1.size() && map.size() < 3; ++i) {
            if (s1[i] != s2[i])
                map.push_back({map.empty() ? s1[i] : s2[i], map.empty() ? s2[i] : s1[i]});
        }
        return map.empty() || (map.size() == 2 && map[0] == map[1]);
    }
};
// @lc code=end

