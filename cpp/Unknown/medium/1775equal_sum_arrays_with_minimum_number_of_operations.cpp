/*
 * @lc app=leetcode id=1775 lang=cpp
 *
 * [1775] Equal Sum Arrays With Minimum Number of Operations
 *
 * https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/description/
 *
 * algorithms
 * Medium (49.47%)
 * Likes:    155
 * Dislikes: 2
 * Total Accepted:    5.1K
 * Total Submissions: 10.2K
 * Testcase Example:  '[1,2,3,4,5,6]\n[1,1,2,2,2,2]'
 *
 * You are given two arrays of integers nums1 and nums2, possibly of different
 * lengths. The values in the arrays are between 1 and 6, inclusive.
 * 
 * In one operation, you can change any integer's value in any of the arrays to
 * any value between 1 and 6, inclusive.
 * 
 * Return the minimum number of operations required to make the sum of values
 * in nums1 equal to the sum of values in nums2. Return -1​​​​​ if it is not
 * possible to make the sum of the two arrays equal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
 * Output: 3
 * Explanation: You can make the sums of nums1 and nums2 equal with 3
 * operations. All indices are 0-indexed.
 * - Change nums2[0] to 6. nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2].
 * - Change nums1[5] to 1. nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2].
 * - Change nums1[2] to 2. nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,1,1,1,1,1], nums2 = [6]
 * Output: -1
 * Explanation: There is no way to decrease the sum of nums1 or to increase the
 * sum of nums2 to make them equal.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [6,6], nums2 = [1]
 * Output: 3
 * Explanation: You can make the sums of nums1 and nums2 equal with 3
 * operations. All indices are 0-indexed. 
 * - Change nums1[0] to 2. nums1 = [2,6], nums2 = [1].
 * - Change nums1[1] to 2. nums1 = [2,2], nums2 = [1].
 * - Change nums2[0] to 4. nums1 = [2,2], nums2 = [4].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * 1 <= nums1[i], nums2[i] <= 6
 * 
 * 
 */

// Greedy
// @lc code=start
// Counting sort; O(n)
class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2)
    {
        if (n1.size() * 6 < n2.size() || n2.size() * 6 < n1.size()) return -1;
        int sum1 = accumulate(begin(n1), end(n1), 0);
        int sum2 = accumulate(begin(n2), end(n2) ,0);

        if (sum1 > sum2) swap(n1, n2);

        vector<int> cnt(6);
        int diff = abs(sum1 - sum2);
        int res = 0;

        for (auto n : n1) {
            ++cnt[6 - n];
        }
        for (auto n : n2) {
            ++cnt[n - 1];
        }
        for (int i = 5; i > 0 && diff >= 0; --i) {
            int take = min(cnt[i], diff / i + (diff % i != 0));
            diff -= take * i;
            res += take;
        }
        return res;
    }
};
// @lc code=end

// Heap - priority_queue, O(nlogn)
// class Solution {
// public:
//     int minOperations(vector<int>& n1, vector<int>& n2)
//     {
//         if (n1.size() * 6 < n2.size() || n2.size() * 6 < n1.size()) return -1;
//         int sum1 = accumulate(begin(n1), end(n1), 0);
//         int sum2 = accumulate(begin(n2), end(n2) ,0);

//         if (sum1 > sum2) swap(n1, n2);
        
//         priority_queue<int, vector<int>, greater<int>> q1(begin(n1), end(n1));
//         priority_queue<int> q2(begin(n2), end(n2));
//         // use make_heap to utilize n1 & n2 for memory O(1).
//         int cnt = 0;
//         int diff = abs(sum1 - sum2);

//         while (diff > 0) {
//             ++cnt;
//             if (q1.empty() || (!q2.empty() && q2.top() - 1 > 6 - q1.top())) {
//                 diff -= q2.top() - 1;
//                 q2.pop();
//             }
//             else {
//                 diff -= 6 - q1.top();
//                 q1.pop();
//             }
//         }
//         return cnt;
//     }
// };
