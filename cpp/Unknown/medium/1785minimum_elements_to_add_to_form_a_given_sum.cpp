/*
 * @lc app=leetcode id=1785 lang=cpp
 *
 * [1785] Minimum Elements to Add to Form a Given Sum
 *
 * https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/
 *
 * algorithms
 * Medium (38.18%)
 * Likes:    59
 * Dislikes: 56
 * Total Accepted:    7.1K
 * Total Submissions: 18.4K
 * Testcase Example:  '[1,-1,1]\n3\n-4'
 *
 * You are given an integer array nums and two integers limit and goal. The
 * array nums has an interesting property that abs(nums[i]) <= limit.
 * 
 * Return the minimum number of elements you need to add to make the sum of the
 * array equal to goal. The array must maintain its property that abs(nums[i])
 * <= limit.
 * 
 * Note that abs(x) equals x if x >= 0, and -x otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,-1,1], limit = 3, goal = -4
 * Output: 2
 * Explanation: You can add -2 and -3, then the sum of the array will be 1 - 1
 * + 1 - 2 - 3 = -4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,-10,9,1], limit = 100, goal = 0
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= limit <= 10^6
 * -limit <= nums[i] <= limit
 * -10^9 <= goal <= 10^9
 * 
 * 
 */
// The range of elements that can be added: abs(e)<=limit
// The gap between sum and goal is abs(goal-sum)
// To use minimal elements we should use element as big as possible, which is limit
// The remainder after division by limit is smaller than limit so it can be covered
//     by one more elements
// So we just need round-up int result of abs(goal-sum) divided by limit,
// which equals to (abs(sum - goal) + limit - 1) / limit                                                                                                     
// @lc code=start
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0ll);
        return (abs(sum - goal) + limit - 1) / limit;
    }
};
// @lc code=end

// My solution
// class Solution {
// public:
//     int minElements(vector<int>& nums, int limit, int goal)
//     {
//         long sum = 0;
//         for (auto n : nums) {
//             sum += n;
//         }
//         long diff = abs(goal - sum);
//         int res = 0;
//         int start = diff <= limit ? diff : limit;
//         for (int i = start; i > 0; --i) {
//             long need = diff / i;
//             res += need;
//             diff -= i * need;
//             if (diff == 0) break;
//         }
//         return res;
//     }
// };
