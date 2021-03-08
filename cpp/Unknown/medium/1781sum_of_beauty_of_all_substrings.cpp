/*
 * @lc app=leetcode id=1781 lang=cpp
 *
 * [1781] Sum of Beauty of All Substrings
 *
 * https://leetcode.com/problems/sum-of-beauty-of-all-substrings/description/
 *
 * algorithms
 * Medium (44.77%)
 * Likes:    66
 * Dislikes: 44
 * Total Accepted:    3.9K
 * Total Submissions: 8.7K
 * Testcase Example:  '"aabcb"'
 *
 * The beauty of a string is the difference in frequencies between the most
 * frequent and least frequent characters.
 * 
 * 
 * For example, the beauty of "abaacc" is 3 - 1 = 2.
 * 
 * 
 * Given a string s, return the sum of beauty of all of its substrings.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aabcb"
 * Output: 5
 * Explanation: The substrings with non-zero beauty are
 * ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabcbaa"
 * Output: 17
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <=^ 500
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int beautySum(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cnt[26] = {};
            for (int j = i; j < s.size(); ++j) {
                ++cnt[s[j] - 'a'];
                int minv = INT_MAX;
                int maxv = -1;
                for (int k = 0; k < 26; ++k) {
                    if (cnt[k] > 0) {
                        minv = min(minv, cnt[k]);
                        maxv = max(maxv, cnt[k]);
                    }
                }
                res += maxv - minv;
            }
        }
        return res;
    }
};
// @lc code=end

