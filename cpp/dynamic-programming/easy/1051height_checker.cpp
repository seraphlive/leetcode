/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 *
 * https://leetcode.com/problems/height-checker/description/
 *
 * algorithms
 * Easy (72.22%)
 * Likes:    369
 * Dislikes: 1740
 * Total Accepted:    106.3K
 * Total Submissions: 147.3K
 * Testcase Example:  '[1,1,4,2,1,3]'
 *
 * Students are asked to stand in non-decreasing order of heights for an annual
 * photo.
 * 
 * Return the minimum number of students that must move in order for all
 * students to be standing in non-decreasing order of height.
 * 
 * Notice that when a group of students is selected they can reorder in any
 * possible way between themselves and the non selected students remain on
 * their seats.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights = [1,1,4,2,1,3]
 * Output: 3
 * Explanation: 
 * Current array : [1,1,4,2,1,3]
 * Target array  : [1,1,1,2,3,4]
 * On index 2 (0-based) we have 4 vs 1 so we have to move this student.
 * On index 4 (0-based) we have 1 vs 3 so we have to move this student.
 * On index 5 (0-based) we have 3 vs 4 so we have to move this student.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [5,1,2,3,4]
 * Output: 5
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: heights = [1,2,3,4,5]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int heightChecker(vector<int>& heights)
    {
        vector<int> bucket(101, 0);
        for (int h : heights) {
            ++bucket[h];
        }
        int res = 0, bptr = 1;
        for (int h : heights) {
            while (bucket[bptr] == 0) {
                ++bptr;
            }
            if (h != bptr) ++res;
            --bucket[bptr];
        }
        return res;
    }
};
// @lc code=end

// Just simple sort
// class Solution {
// public:
//     int heightChecker(vector<int>& heights) {
//         vector<int> sorted = heights;
//         sort(sorted.begin(), sorted.end());
//         int cnt = 0;
//         for (int i = 0; i < sorted.size(); ++i) {
//             if (heights[i] != sorted[i]) {
//                 ++cnt;
//             }
//         }
//         return cnt;
//     }
// };