/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (54.61%)
 * Likes:    2747
 * Dislikes: 410
 * Total Accepted:    294K
 * Total Submissions: 538.4K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given an integer array nums where every element appears three times except
 * for one, which appears exactly once. Find the single element and return it.
 *
 * You must implement a solution with a linear runtime complexity and use only
 * constant extra space.
 *
 *
 * Example 1:
 * Input: nums = [2,2,3,2]
 * Output: 3
 * Example 2:
 * Input: nums = [0,1,0,1,0,1,99]
 * Output: 99
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each element in nums appears exactly three times except for one element
 * which appears once.
 *
 *
 */

// @lc code=start
// General Method: every element appears k times except for one element appears
// exactly m times.
// An integer number has 32 bits, we check each bits for every number in the
// array. so O(32n), O(1). For each bit, count the number of 1s from the
// corresponding bit of all the numbers. If the count % k == m, which means
// either only that bit of target number is one or both target and non-target
// numbers have that bit to be 1. In both the target number should have that bit
// to be 1. Otherwise if count % k == 0, which means only non-target numbers
// have that bit to be 1, so the target should have that bit to be 0. In this
// way we can set every bit of target number and return it.
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int k = 3, m = 1;
    int res = 0;
    for (int bit = 0; bit < 32; ++bit) {
      int cnt = 0;
      for (int i = 0; i < nums.size(); ++i) {
        cnt += nums[i] >> bit & 1;
      }
      res |= (cnt % k == m ? 1 : 0) << bit;
    }
    return res;
  }
};
// @lc code=end
