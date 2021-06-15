/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (58.18%)
 * Likes:    7907
 * Dislikes: 823
 * Total Accepted:    543.7K
 * Total Submissions: 934.9K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array of integers nums containing n + 1 integers where each integer
 * is in the range [1, n] inclusive.
 * 
 * There is only one repeated number in nums, return this repeated number.
 * 
 * You must solve the problem without modifying the array nums and uses only
 * constant extra space.
 * 
 * 
 * Example 1:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 * Example 2:
 * Input: nums = [3,1,3,4,2]
 * Output: 3
 * Example 3:
 * Input: nums = [1,1]
 * Output: 1
 * Example 4:
 * Input: nums = [1,1,2]
 * Output: 1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All the integers in nums appear only once except for precisely one integer
 * which appears two or more times.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * How can we prove that at least one duplicate number must exist in nums?
 * Can you solve the problem in linear runtime complexity?
 * 
 * 
 */
// TODO: 2-pointers method.
// @lc code=start
// Binary search on range [1, n]. For each mid, count elements <= mid. If there
// is no duplicate on the left, cnt should == mid, we then go to [mid+1, r].
// Else cnt > mid which means duplicate is in [l, mid];
class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 1, r = n - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        if (nums[i] <= mid) ++cnt;
      }
      if (cnt > mid) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
// @lc code=end
