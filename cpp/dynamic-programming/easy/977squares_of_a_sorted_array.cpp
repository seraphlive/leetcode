/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * https://leetcode.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (72.25%)
 * Likes:    1941
 * Dislikes: 111
 * Total Accepted:    401.5K
 * Total Submissions: 555.7K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * Given an integer array nums sorted in non-decreasing order, return an array
 * of the squares of each number sorted in non-decreasing order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [-4,-1,0,3,10]
 * Output: [0,1,9,16,100]
 * Explanation: After squaring, the array becomes [16,1,0,9,100].
 * After sorting, it becomes [0,1,9,16,100].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-7,-3,2,3,11]
 * Output: [4,9,9,49,121]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums is sorted in non-decreasing order.
 * 
 * 
 * 
 * Follow up: Squaring each element and sorting the new array is very trivial,
 * could you find an O(n) solution using a different approach?
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> res(nums.size());
        auto l = nums.begin();
        auto r = nums.rbegin();
        for (auto it = res.rbegin(); it != res.rend(); ++it) {
            if (abs(*r) > abs(*l)) {
                *it = pow(abs(*r), 2);
                ++r;
            }
            else {
                *it = pow(abs(*l), 2);
                ++l;
            }
        }
        return res;
    }
};
// @lc code=end

// One obvious solution with squaring and sorting
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         for (auto& n : nums) {
//             n = pow(n, 2);
//         }
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

// No iterator
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int> res(nums.size());
//         int l = 0, r = nums.size() - 1;
//         for (int p = nums.size() - 1; p >= 0; --p) {
//             if (abs(nums[r]) > abs(nums[l])) {
//                 res[p] = pow(nums[r], 2);
//                 --r;
//             } else {
//                 res[p] = pow(nums[l], 2);
//                 ++l; 
//             }
//         }
//         return res;
//     }
// };