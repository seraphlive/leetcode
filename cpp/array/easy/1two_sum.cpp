/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (46.33%)
 * Likes:    19410
 * Dislikes: 690
 * Total Accepted:    3.9M
 * Total Submissions: 8.4M
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
 * 2 <= nums.length <= 10^3
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 */

// @lc code=start
// hashtable
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            if (map.count(left) && map[left] != i) return {i, map[left]};
        }
        return {};
    }
};
// @lc code=end

// brute force
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for (int i = 0; i < nums.size(); ++i) {
//             for (int j = i + 1; j < nums.size(); ++j) {
//                 int sum = nums[i] + nums[j];
//                 if (sum == target) return {i, j};
//             }
//         }
//         return {};
//     }
// };
