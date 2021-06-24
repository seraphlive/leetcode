/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.18%)
 * Likes:    6008
 * Dislikes: 2010
 * Total Accepted:    536.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
// 1. Iterate from the end along a non-decreasing sequence and stop at the first
// number that is decreasing.
// 2. Reverse [i+1~end]. If i is already out of bound as -1, return directly.
// 3. Otherwise iterate from i+1 to find the first number that is bigger than
// n[i] and swap it with n[i].
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    reverse(nums.begin() + i + 1, nums.end());
    if (i == -1) return;

    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] > nums[i]) {
        swap(nums[j], nums[i]);
        return;
      }
    }
  }
};
// @lc code=end
