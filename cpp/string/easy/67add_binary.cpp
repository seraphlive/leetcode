/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (46.77%)
 * Likes:    2519
 * Dislikes: 328
 * Total Accepted:    566.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b)
    {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;

        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            res += static_cast<char>(c % 2 + '0');
            c /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

