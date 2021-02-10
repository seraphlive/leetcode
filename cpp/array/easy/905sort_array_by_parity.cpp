/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 *
 * https://leetcode.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (75.01%)
 * Likes:    1520
 * Dislikes: 85
 * Total Accepted:    296.3K
 * Total Submissions: 395K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array A of non-negative integers, return an array consisting of all
 * the even elements of A, followed by all the odd elements of A.
 * 
 * You may return any answer array that satisfies this condition.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: [2,4,3,1]
 * The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 * 
 */

// @lc code=start
// R&W two pointers but do a sway. Similar with 283.
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int r = 0, w = 0;
        while (r < A.size()) {
            if (A[r] % 2 == 0) {
                swap(A[w++], A[r++]);
            } else {
                ++r;
            }
        }
        return A;
    }
};
// @lc code=end

// Using partition
// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& A) {
//         auto is_even = [](auto e) { return e % 2 == 0; };
//         partition(A.begin(), A.end(), is_even);
//         return A;
//     }
// };
