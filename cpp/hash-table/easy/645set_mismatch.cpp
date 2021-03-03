/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (42.37%)
 * Likes:    1050
 * Dislikes: 416
 * Total Accepted:    115.1K
 * Total Submissions: 270.5K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 * 
 * You are given an integer array nums representing the data status of this set
 * after the error.
 * 
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
// hashtable
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        const int N = nums.size();
        vector<int> map(N + 1);
        vector<int> res(2);
        for (int i = 0; i < N; ++i) {
            ++map[nums[i]];
        }
        for (int i = 1; i < N + 1; ++i) {
            if (map[i] == 0) res[1] = i;
            if (map[i] == 2) res[0] = i;
        }
        return res;
    }
};
// @lc code=end

// MATH. O(N), O(1)
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums)
//     {
//         long n = nums.size();
//         long sum = 0;
//         long sums = 0;
//         for (auto i : nums) {
//             sum += i;
//             sums += i * i;
//         }
        
//         // y - missing; x - duplicate
//         auto a = n * (n + 1) / 2 - sum;  // y - x
//         auto b = n * (n + 1) * (2 * n + 1) / 6 - sums; // y^2 - x^2
//         vector<int> res(2);
//         res[0] = (b / a - a) / 2;
//         res[1] = (b / a + a) / 2;
//         return res;
//     }
// };
