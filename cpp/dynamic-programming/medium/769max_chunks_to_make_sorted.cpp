/*
 * @lc app=leetcode id=769 lang=cpp
 *
 * [769] Max Chunks To Make Sorted
 *
 * https://leetcode.com/problems/max-chunks-to-make-sorted/description/
 *
 * algorithms
 * Medium (56.18%)
 * Likes:    1124
 * Dislikes: 148
 * Total Accepted:    51.1K
 * Total Submissions: 90.9K
 * Testcase Example:  '[4,3,2,1,0]'
 *
 * You are given an integer array arr of length n that represents a permutation
 * of the integers in the range [0, n - 1].
 * 
 * We split arr into some number of chunks (i.e., partitions), and individually
 * sort each chunk. After concatenating them, the result should equal the
 * sorted array.
 * 
 * Return the largest number of chunks we can make to sort the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,3,2,1,0]
 * Output: 1
 * Explanation:
 * Splitting into two or more chunks will not return the required result.
 * For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1,
 * 2], which isn't sorted.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,0,2,3,4]
 * Output: 4
 * Explanation:
 * We can split into two chunks, such as [1, 0], [2, 3, 4].
 * However, splitting into [1, 0], [2], [3], [4] is the highest number of
 * chunks possible.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == arr.length
 * 1 <= n <= 10
 * 0 <= arr[i] < n
 * All the elements of arr are unique.
 * 
 * 
 */

// @lc code=start
// As the array only contains 1~n-1, after being sorted a[i] = i; For each i
// that != a[i], it must be included in [...i] to be sorted. So we choose max
// right end point for the interval to cover previous element and cut at each
// a[i] == r to be the split point of each interval.
class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    if (arr.empty()) return 0;
    int res = 0, r = 0;
    for (int i = 0; i < arr.size(); ++i) {
      r = max(r, arr[i]);
      if (r == i) ++res;
    }
    return res;
  }
};
// @lc code=end

