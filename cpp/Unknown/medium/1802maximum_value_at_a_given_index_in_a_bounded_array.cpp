/*
 * @lc app=leetcode id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 *
 * https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/description/
 *
 * algorithms
 * Medium (25.93%)
 * Likes:    130
 * Dislikes: 27
 * Total Accepted:    3.7K
 * Total Submissions: 14.3K
 * Testcase Example:  '4\n2\n6'
 *
 * You are given three positive integers n, index and maxSum. You want to
 * construct an array nums (0-indexed) that satisfies the following
 * conditions:
 * 
 * 
 * nums.length == n
 * nums[i] is a positive integer where 0 <= i < n.
 * abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
 * The sum of all the elements of nums does not exceed maxSum.
 * nums[index] is maximized.
 * 
 * 
 * Return nums[index] of the constructed array.
 * 
 * Note that abs(x) equals x if x >= 0, and -x otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, index = 2,  maxSum = 6
 * Output: 2
 * Explanation: The arrays [1,1,2,1] and [1,2,2,1] satisfy all the conditions.
 * There are no other valid arrays with a larger value at the given index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, index = 1,  maxSum = 10
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= maxSum <= 10^9
 * 0 <= index < n
 * 
 */

// @lc code=start
// Binary search and a bit math. O(log(maxSum)) O(1)
class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {

    }
private:
    long test(int n, int index, int a)
    {

    }
};
// @lc code=end

// math pyramid layer
// class Solution {
// public:
//     int maxValue(int n, int index, int maxSum)
//     {
//         // put bottom layer
//         int max_value = 1;
//         maxSum -= n;
//         int layer = 1;

//         int need;
//         while (maxSum > 0) {
//             // how many 1s needed for the layer
//             need = 2 * layer - 1;

//             // deal with boundry case
//             int right = (index + layer - 1) - (n - 1);
//             if (right > 0) need -= right;
//             int left = (layer - index - 1);
//             if (left > 0) need -= left;

//             // too many points to use or not enough points for a layer
//             if (need >= n || maxSum < need) break;

//             maxSum -= need;
//             ++layer;
//             ++max_value;
//         }
//         return max_value += (maxSum / n);
//     }
// };
