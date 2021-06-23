/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 *
 * https://leetcode.com/problems/next-greater-element-iii/description/
 *
 * algorithms
 * Medium (33.37%)
 * Likes:    1290
 * Dislikes: 274
 * Total Accepted:    70.5K
 * Total Submissions: 211.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the smallest integer which has exactly the
 * same digits existing in the integer n and is greater in value than n. If no
 * such positive integer exists, return -1.
 *
 * Note that the returned integer should fit in 32-bit integer, if there is a
 * valid answer but it does not fit in 32-bit integer, return -1.
 *
 *
 * Example 1:
 * Input: n = 12
 * Output: 21
 * Example 2:
 * Input: n = 21
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
// Same with Q31, next_permutation.
class Solution {
 public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    if (s.size() == 1) return -1;

    bool res = nextPermutation(s);
    long ans = stol(s);
    return (!res || ans > INT_MAX) ? -1 : ans;
  }

 private:
  bool nextPermutation(string& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) --i;
    if (i == -1) return false;

    reverse(nums.begin() + i + 1, nums.end());
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] > nums[i]) {
        swap(nums[j], nums[i]);
        break;
      }
    }
    return true;
  }
};
// @lc code=end
