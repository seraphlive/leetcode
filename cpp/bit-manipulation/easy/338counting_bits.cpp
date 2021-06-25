/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Easy (71.06%)
 * Likes:    4256
 * Dislikes: 222
 * Total Accepted:    375.9K
 * Total Submissions: 528.9K
 * Testcase Example:  '2'
 *
 * Given an integer n, return an array ans of length n + 1 such that for each i
 * (0 <= i <= n), ans[i] is the number of 1's in the binary representation of
 * i.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [0,1,1]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5
 * Output: [0,1,1,2,1,2]
 * Explanation:
 * 0 --> 0
 * 1 --> 1
 * 2 --> 10
 * 3 --> 11
 * 4 --> 100
 * 5 --> 101
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^5
 *
 *
 *
 * Follow up:
 *
 *
 * It is very easy to come up with a solution with a runtime of O(n log n). Can
 * you do it in linear time O(n) and possibly in a single pass?
 * Can you do it without using any built-in function (i.e., like
 * __builtin_popcount in C++)?
 *
 *
 */

// @lc code=start
// dp. O(n).
// f[i] denotes count of 1s in number i. i & (i - 1) will delete the lowest 1 in
// i. so f[i] = f[i & (i - 1)] + 1;
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> res(n + 1);
    for (int i = 1; i <= n; ++i) {
      res[i] = res[i & (i - 1)] + 1;
    }
    return res;
  }
};
// @lc code=end

// brute force
// class Solution {
//  public:
//   vector<int> countBits(int n) {
//     vector<int> res(n + 1);
//     for (int i = 0; i <= n; ++i) {
//       res[i] = cnt(i);
//     }
//     return res;
//   }

//  private:
//   int cnt(int a) {
//     int res = 0;
//     while (a) {
//       if (a & 1) ++res;
//       a >>= 1;
//     }
//     return res;
//   }
// };
