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
// Binary search and a bit math optimised from greedy, O(logn)
// For a specific index, take O(1) to calculate the minimal sum (we only neet to maximize the peak)
// and compare with maxSum
// 
// n=6 index=1 maxSum=18
// 4 5 4 3 2 1 sum=lsum + rsum - n[index] (use (a1 + an) * n / 2)
// lsum|
//   | rsum
// Then use binary search to find the max peak.
class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {
        // calculate from n[index]=1
        int ans = 1;
        int left = 1;
        int right = maxSum;

        while (left <= right) {
            int mid = (left + right) / 2;
            bool checker = check(n, index, maxSum, mid);
            if (checker) right = mid - 1;
            else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
private:
    long getSum(long peak, int length)
    {
        long sum = 0;
        if (length > peak) {
            sum += (peak + 1) * peak / 2;
            sum += length - peak;
        }
        else {
            long min = peak - length + 1;
            sum += (min + peak) * length / 2;
        }
        return sum;
    }
    
    bool check(int n, int index, int maxSum, int peak)
    {
        long sum = getSum(peak, index + 1) + getSum(peak, n - index) - peak;
        return sum > static_cast<long>(maxSum);
    }
};
// @lc code=end

// Greedy, O(n), TLE
// Index is peak position
// To keep height difference 1, when we add 1 to a position, it will affect its next neighbour.
// n=6 index=1 maxSum=18
// 1 1 1 1 1 1 sum=6
// 1 2 1 1 1 1 sum=7
// 2 3 2 1 1 1 sum=10
// 3 4 3 2 1 1 sum=14 => result
// 4 5 4 3 2 1 sum=19>18 stop
// class Solution {
// public:
//     int maxValue(int n, int index, int maxSum)
//     {
//         // calculate from n[index]=1
//         int ans = 1;
//         int sum = n;
//         int left = index;
//         int right = index;

//         while (true) {
//             sum = sum + (right - left + 1);
//             if (sum > maxSum) break;
//             ++ans;

//             if (left > 0) --left;
//             if (right < n - 1) ++right;
//         }
//         return ans;
//     }
// };

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
