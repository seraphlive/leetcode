/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (65.28%)
 * Likes:    4539
 * Dislikes: 133
 * Total Accepted:    257K
 * Total Submissions: 393.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

// @lc code=start
// Monotonic stack. For each element, find the first element on the right that
// is bigger than it.
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& t) {
    stack<int> st;
    vector<int> res(t.size(), 0);
    for (int i = 0; i < t.size(); ++i) {
      while (!st.empty() && t[i] > t[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
// @lc code=end

// Directly calculation without using stack. If calculating from the end of the
// sequence, for each i, all future temperatures have all been determined. So
// we can check from j=i+1, and jump res[j] steps if res[j]!=0.
// class Solution {
//  public:
//   vector<int> dailyTemperatures(vector<int>& t) {
//     vector<int> res(t.size());
//     for (int i = t.size() - 1; i >= 0; --i) {
//       int j = i + 1;
//       while (j < t.size() && t[j] <= t[i]) {
//         if (res[j] > 0) {
//           j += res[j];
//         } else {
//           j = t.size();
//         }
//       }
//       if (j < t.size()) res[i] = j - i;
//     }
//     return res;
//   }
// };
