/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.10%)
 * Likes:    21836
 * Dislikes: 742
 * Total Accepted:    4.4M
 * Total Submissions: 9.4M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start
// hash table (one pass). O(n), O(n).
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty()) return {};
    unordered_map<int, int> ht;
    for (int i = 0; i < nums.size(); ++i) {
      int t = nums[i];
      if (ht.find(t) != ht.end()) {
        return {i, ht[t]};
      } else {
        ht[target - t] = i;
      }
    }
    return {};
  }
};
// @lc code=end

// brute-force O(n^2), O(1).
// class Solution {
// public:
//   vector<int> twoSum(vector<int>& nums, int target) {
//     if (nums.empty()) return {};
//     for (int i = 0; i < nums.size(); ++i) {
//       for (int j = i + 1; j < nums.size(); ++j) {
//         if (nums[i] + nums[j] == target) return {i, j};
//       }
//     }
//     return {};
//   }
// };
