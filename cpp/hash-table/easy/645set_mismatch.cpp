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
// Math. O(n), O(1).
using LL = long long;

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    LL n = nums.size();
    LL sum = 0, sums = 0;
    for (int i : nums) {
      sum += i;
      sums += i * i;
    }

    LL a = n * (n + 1) / 2 - sum; // mis - dup
    LL b = n * (n + 1) * (2 * n + 1) / 6 - sums; // mis^2 - dup^2
    int dup = (b / a - a) / 2;
    int mis = (b / a + a) / 2;
    return {dup, mis};
  }
};
// @lc code=end

// hashtable, O(n), O(n).
// class Solution {
// public:
//   vector<int> findErrorNums(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> map(n + 1);
//     for (int i : nums) ++map[i];

//     int dup = -1, mis = -1;
//     for (int i = 1; i <= n; ++i) {
//       if (map[i] == 0) mis = i;
//       if (map[i] == 2) dup = i;
//     }
//     return {dup, mis};
//   }
// };

// In-place tagging elements. O(n), O(1). (original input is modified)
// class Solution {
// public:
//   vector<int> findErrorNums(vector<int>& nums) {
//     int dup = -1, mis = -1;
//     for (int i : nums) {
//       if (nums[abs(i) - 1] < 0) {
//         dup = abs(i);
//       } else {
//         nums[abs(i) - 1] *= -1;
//       }
//     }
//     for (int i = 0; i < nums.size(); ++i) {
//       if (nums[i] > 0) mis = i + 1;
//     }
//     return {dup, mis};
//   }
// };
