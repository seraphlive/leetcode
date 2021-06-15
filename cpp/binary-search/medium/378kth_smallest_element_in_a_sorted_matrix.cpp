/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (57.00%)
 * Likes:    3796
 * Dislikes: 186
 * Total Accepted:    268K
 * Total Submissions: 470K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given an n x n matrix where each of the rows and columns are sorted in
 * ascending order, return the k^th smallest element in the matrix.
 * 
 * Note that it is the k^th smallest element in the sorted order, not the k^th
 * distinct element.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
 * Output: 13
 * Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and
 * the 8^th smallest number is 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[-5]], k = 1
 * Output: -5
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length
 * n == matrix[i].length
 * 1 <= n <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * All the rows and columns of matrix are guaranteed to be sorted in
 * non-decreasing order.
 * 1 <= k <= n^2
 * 
 * 
 */
// 1  5  9
// 10 11 13
// 12 13 15
// @lc code=start   
// Binary search solution: search on the value range and begin with l=minimum &
// r=maximum, together O(log(max - min)). For each loop, we find the count of
// elements <= mid and compare cnt with k as checking condition.
class Solution {
public:
  int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat[0].size();
    int l = mat[0][0], r = mat[n - 1][n - 1];
    while (l < r) {
      int mid = l + (r - l) / 2;
      int cnt = 0, j = n - 1;
      for (int i = 0; i < n; ++i) {
        while (j >= 0 && mat[i][j] > mid) --j;
        cnt += (j + 1);
      }
      if (cnt < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
};
// @lc code=end

// heap solution: Use a heap to help sorting. Pop the min value each time and
// the k-th poped element is the result.
// First construct the heap with the first row. The heap size is n so space
// complexity is O(n). Time for constructing heap is min(k, n) (no need more
// elements if k < n). Then repeat k-1 times: pop the min value and insert the
// element below the poped one from the matrix. After all that, pop the min
// value as the result. heap insert takes O(logn) so final time complexity is
// O(min(k, n)+klogn) which can be O(n^2logn) 
// class Solution {
// public:
//   int kthSmallest(vector<vector<int>>& mat, int k) {
//     int n = mat[0].size();
//     priority_queue<Element, vector<Element>, greater<Element>> heap;

//     for (int i = 0; i < n && i < k; ++i) {
//       Element t = {mat[0][i], 0, i};
//       heap.push(t);
//     }

//     for (int i = 0; i < k - 1; ++i) {
//       auto t = heap.top();
//       heap.pop();
//       if (t.x == n - 1) continue;
//       Element nt = {mat[t.x + 1][t.y], t.x + 1, t.y};
//       heap.push(nt);
//     }
//     return heap.top().e;
//   }
// private:
//   struct Element {
//     int e, x, y;
//     bool operator>(const Element& E) const {
//       return e > E.e;
//     }
//   };
// };
