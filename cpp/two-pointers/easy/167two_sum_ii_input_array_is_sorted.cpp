/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (55.71%)
 * Likes:    2434
 * Dislikes: 696
 * Total Accepted:    536.9K
 * Total Submissions: 963.7K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers numbers that is already sorted in ascending
 * order, find two numbers such that they add up to a specific target number.
 * 
 * Return the indices of the two numbers (1-indexed) as an integer array answer
 * of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
 * 
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in increasing order.
 * -1000 <= target <= 1000
 * Only one valid answer exists.
 * 
 * 
 */

// @lc code=start
// two-pointers
// because it's already sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int lo = 0;
        int hi = numbers.size() - 1;
        while (numbers[lo] + numbers[hi] != target) {
            if (numbers[lo] + numbers[hi] < target) ++lo;
            else --hi;
        }
        return {lo + 1, hi + 1};
    }
};
// @lc code=end

// hashtable
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target)
//     {
//         unordered_map<int, int> map;
//         for (int i = 0; i < numbers.size(); ++i) {
//             map[numbers[i]] = i + 1;
//         }
//         for (int i = 0; i < numbers.size(); ++i) {
//             int need = target - numbers[i];
//             if (map.count(need) && map[need] != i + 1) {
//                 if (map[need] < i + 1) return {map[need], i + 1};
//                 else return {i + 1, map[need]};
//             }
//         }
//         return {};
//     }
// };
