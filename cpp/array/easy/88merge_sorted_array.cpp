/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (40.59%)
 * Likes:    3297
 * Dislikes: 4940
 * Total Accepted:    789.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively. You may assume that nums1 has a size equal to m + n such that
 * it has enough space to hold additional elements from nums2.
 * 
 * 
 * Example 1:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Example 2:
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n)
    {
        int p1 = m - 1, p2 = n - 1, l = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            if (A[p1] > B[p2]) {
                A[l--] = A[p1--];
            }
            else {
                A[l--] = B[p2--];
            }
        }
        while (p2 >= 0) {
            A[l--] = B[p2--];
        }
    }
};
// @lc code=end

