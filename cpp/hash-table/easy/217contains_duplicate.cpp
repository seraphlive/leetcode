/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (57.47%)
 * Likes:    1854
 * Dislikes: 853
 * Total Accepted:    843.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
// hashtable, set,O(n), O(n).
class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    if (nums.empty()) return false;

    unordered_set<int> ht;
    for (int n : nums) {
      if (ht.find(n) != ht.end()) {
        return true;
      } else {
        ht.insert(n);
      }
    }
    return false;
  }
};
// @lc code=end

// hashtable, crafted map,O(n), O(n).
// class Solution {
// public:
//   bool containsDuplicate(vector<int>& nums) {
//     if (nums.empty()) return false;

//     unordered_map<int, int> ht;
//     for (int n : nums) {
//       if (ht.find(n) != ht.end()) {
//         ++ht[n];
//         if (ht[n] >= 2) return true;
//       } else {
//         ht[n] = 1;
//       }
//     }
//     return false;
//   }
// };
