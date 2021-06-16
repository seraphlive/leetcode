/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (54.71%)
 * Likes:    1408
 * Dislikes: 989
 * Total Accepted:    113.8K
 * Total Submissions: 207.9K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * 
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,2,3,1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,2,3,1,4,2]
 * Output: 6
 * Explanation: 
 * The degree is 3 because the element 2 is repeated 3 times.
 * So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 * 
 */

// @lc code=start
// For each unique number x in nums, we count its frequency and its first occurrence
// index. If x has maximum freq, update degree = count[a] and len = i - first[nums[i]] + 1.
// If x is one of the numbers that has maximum freq, update res if the len is smaller.
// O(n) O(n).
class Solution {
public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> count, first;
    int res = 0, degree = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (first.find(nums[i]) == first.end()) first[nums[i]] = i;
      if (++count[nums[i]] > degree) {
        degree = count[nums[i]];
        res = i - first[nums[i]] + 1;
      } else if (count[nums[i]] == degree) {
        res = min(res, i - first[nums[i]] + 1);
      }
    }
    return res;
  }
};
// @lc code=end

