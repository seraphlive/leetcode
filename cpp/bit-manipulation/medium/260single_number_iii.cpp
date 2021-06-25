/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (65.56%)
 * Likes:    2454
 * Dislikes: 136
 * Total Accepted:    196K
 * Total Submissions: 299K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an integer array nums, in which exactly two elements appear only once
 * and all the other elements appear exactly twice. Find the two elements that
 * appear only once. You can return the answer in any order.
 *
 * You must write an algorithm that runs in linear runtime complexity and uses
 * only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,3,2,5]
 * Output: [3,5]
 * Explanation:  [5, 3] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,0]
 * Output: [-1,0]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,1]
 * Output: [1,0]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 3 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * Each integer in nums will appear twice, only two integers will appear once.
 *
 *
 */

// @lc code=start
// 1. XOR all numbers, only target numbers x, y will be left in diff = x^y. diff
// denotes all the digits that is different between x and y.
// 2. diff &= -diff to get the first lowest bit that is different.
// 3. Scan the array again to use this bit to distinguish x and y. Note that all
// other numbers will be seperated into two groups while doing this and
// eliminate during the XORing.
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    // long diff = 0;
    int diff = 0;
    for (int n : nums) diff ^= n;
    // diff &= -diff;
    // Use shifting to find first different bit to avoid overflowing
    int pos = 0;
    for (int i = 0; i < 32; ++i) {
      if (diff >> i & 1) {
        pos = i;
        break;
      }
    }

    vector<int> res(2);
    for (int n : nums) {
      // if ((n & diff) == 0) {
      if (n >> pos & 1) {
        res[0] ^= n;
      } else {
        res[1] ^= n;
      }
    }
    return res;
  }
};
// @lc code=end
