/*
 * @lc app=leetcode id=1784 lang=cpp
 *
 * [1784] Check if Binary String Has at Most One Segment of Ones
 *
 * https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/
 *
 * algorithms
 * Easy (42.93%)
 * Likes:    41
 * Dislikes: 114
 * Total Accepted:    9.4K
 * Total Submissions: 21.9K
 * Testcase Example:  '"1001"'
 *
 * Given a binary string s ​​​​​without leading zeros, return true​​​ if s
 * contains at most one contiguous segment of ones. Otherwise, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "1001"
 * Output: false
 * Explanation: The ones do not form a contiguous segment.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "110"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s[i]​​​​ is either '0' or '1'.
 * s[0] is '1'.
 * 
 * 
 */
// Find the first 1 and last 1 ins
// If no 0 between them return true
// the solution works even without s[0] = '1'
// @lc code=start
class Solution {
public:
    bool checkOnesSegment(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j && s[i] == '0') ++i;
        while (i <= j && s[j] == '0') --j;
        for (int k = i; k <= j; ++k) {
            if (s[k] == '0') return false;
        }
        return true;
    }
};
// @lc code=end

// My solution
// class Solution {
// public:
//     bool checkOnesSegment(string s)
//     {
//         if (s.empty()) return false;
//         bool res = false;
//         bool flag = false;
//         int cnt = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == '1') {
//                 if (!flag) {
//                     res = true;
//                     flag = true;
//                     ++cnt;
//                     if (cnt > 1) {
//                         res = false;
//                         break;
//                     }
//                 }
//             }
//             else {
//                 flag = false;
//             }
//         }
//         return res;
//     }
// };
