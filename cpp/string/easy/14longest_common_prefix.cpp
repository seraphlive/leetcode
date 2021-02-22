/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.06%)
 * Likes:    3720
 * Dislikes: 2136
 * Total Accepted:    951.3K
 * Total Submissions: 2.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int min = 200;
        string min_str = "";
        int cnt = 0;

        for (string s : strs) {
            if (s.size() <= min) {
                min = s.size();
                min_str = s;
            }
        }
        for (int j = 0; j < min; ++j) {
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i][j] != min_str[j]) return min_str.substr(0, cnt);
            }
            ++cnt;
        }
        return min_str.substr(0, cnt);
    }
};
// @lc code=end

