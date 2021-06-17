/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 *
 * https://leetcode.com/problems/array-nesting/description/
 *
 * algorithms
 * Medium (56.16%)
 * Likes:    1101
 * Dislikes: 120
 * Total Accepted:    66K
 * Total Submissions: 117.5K
 * Testcase Example:  '[5,4,0,3,1,6,2]'
 *
 * You are given an integer array nums of length n where nums is a permutation
 * of the numbers in the range [0, n - 1].
 * 
 * You should build a set s[k] = {nums[k], nums[nums[k]], nums[nums[nums[k]]],
 * ... } subjected to the following rule:
 * 
 * 
 * The first element in s[k] starts with the selection of the element nums[k]
 * of index = k.
 * The next element in s[k] should be nums[nums[k]], and then
 * nums[nums[nums[k]]], and so on.
 * We stop adding right before a duplicate element occurs in s[k].
 * 
 * 
 * Return the longest length of a set s[k].
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,4,0,3,1,6,2]
 * Output: 4
 * Explanation: 
 * nums[0] = 5, nums[1] = 4, nums[2] = 0, nums[3] = 3, nums[4] = 1, nums[5] =
 * 6, nums[6] = 2.
 * One of the longest sets s[k]:
 * s[0] = {nums[0], nums[5], nums[6], nums[2]} = {5, 6, 2, 0}
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] < nums.length
 * All the values of nums are unique.
 * 
 * 
 */

// @lc code=start
// See it as a iteration of linked list and find circle problem. For each point,
// we will definitely go back to itself (has cycle). As numbers are all unique,
// Each number can only be in one specific cycle, so no need to go to that cycle
// again if it has already been visited.
class Solution {
public:
  int arrayNesting(vector<int>& nums) {
    int n = nums.size();
    vector<int> st(n, 1);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      for (int j = i; st[nums[j]] != -1; j = nums[j]) {
        st[nums[j]] = -1;
        ++cnt;
      }
      res = max(res, cnt);
    }
    return res;
  }
};
// @lc code=end

