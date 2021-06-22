/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (51.52%)
 * Likes:    1216
 * Dislikes: 129
 * Total Accepted:    98.7K
 * Total Submissions: 191.6K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmonious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Given an integer array nums, return the length of its longest harmonious
 * subsequence among all its possible subsequences.
 * 
 * A subsequence of array is a sequence that can be derived from the array by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,1,1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
// Use hash-table to store the freq of each number, and the h subseq should only
// contains two numbers that differ by 1 (with duplication). So the length for
// each har-subseq is the sum of the cnt of both elements.
// O(n), O(n).
class Solution {
public:
  int findLHS(vector<int>& nums) {
    if (nums.empty()) return 0;

    int res = 0;
    unordered_map<int, int> ht;
    for (int n : nums) {
      ht[n] = (ht.find(n) == ht.end() ? 1 : ht[n] + 1);
      if (ht.find(n + 1) != ht.end()) res = max(res, ht[n] + ht[n + 1]);
      if (ht.find(n - 1) != ht.end()) res = max(res, ht[n] + ht[n - 1]);
    }
    return res;
  }
};
// @lc code=end

