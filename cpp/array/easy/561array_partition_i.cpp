/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition I
 *
 * https://leetcode.com/problems/array-partition-i/description/
 *
 * algorithms
 * Easy (73.21%)
 * Likes:    135
 * Dislikes: 37
 * Total Accepted:    251.6K
 * Total Submissions: 343.7K
 * Testcase Example:  '[1,4,3,2]'
 *
 * Given an integer array nums of 2n integers, group these integers into n
 * pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for
 * all i is maximized. Return the maximized sum.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,3,2]
 * Output: 4
 * Explanation: All possible pairings (ignoring the ordering of elements) are:
 * 1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
 * 2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
 * 3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
 * So the maximum possible sum is 4.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [6,2,6,5,1,2]
 * Output: 9
 * Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) +
 * min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * nums.length == 2 * n
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums)
    {
        const int maxValue = 10000;
        array<int, 2 * maxValue + 1> c{};

        for (int num : nums) ++c[num + maxValue];

        int res = 0;
        int n = -maxValue;
        bool first = true;

        while (n <= maxValue) {
            if (!c[n + maxValue]) {
                ++n;
                continue;
            }
            if (first) {
                res += n;
                first = false;
            }
            else {
                first = true;
            }
            --c[n + maxValue];
        }
        return res;
    }
};
// @lc code=end

// O(nlogn)
// class Solution {
// public:
//     int arrayPairSum(vector<int>& nums)
//     {
//         int sum = 0;
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i += 2) {
//             sum += nums[i];
//         }
//         return sum;
//     }
// };

