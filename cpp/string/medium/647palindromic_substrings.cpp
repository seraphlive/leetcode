/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (62.96%)
 * Likes:    4526
 * Dislikes: 141
 * Total Accepted:    296.2K
 * Total Submissions: 470.2K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 * 
 * A string is a palindrome when it reads the same backward as forward.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
// extend from center pointer. O(n^2), O(1). Function call for odd/even.
// Can be optimized to O(n) using Manacher algorithm.
class Solution {
public:
  int countSubstrings(string s) {
    if (s.empty()) return 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
      dextend(s, i, i, cnt); // odd length, i is mid point.
      dextend(s, i, i + 1, cnt); // even length, mid is between [i,i+1].
    }
    return cnt;
  }
private:
  void dextend(string& s, int l, int r, int& cnt) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      ++cnt;
      --l;
      ++r;
    }
  }
};
// @lc code=end

// extend from center pointer. O(n^2), O(1). Calculate indices.
// Can be optimized to O(n) using Manacher algorithm.
// class Solution {
// public:
//   int countSubstrings(string s) {
//     int cnt = 0;
//     int n = s.size();
//     for (int i = 0; i < 2 * n - 1; ++i) {
//       // for s with length n, 2n-1 possible mid positions in total, denoted by i.
//       int l = i / 2;
//       int r = l + i % 2; // if odd r=l, else r = l + 1;
//       while (l >= 0 && r < n && s[l] == s[r]) {
//         ++cnt;
//         --l;
//         ++r;
//       }
//     }
//     return cnt;
//   }
// };

// DP, O(n^2), O(n^2)
// f[i][j] denotes if s[i...j] is a palindromic substring.
// f[i][i]=1, f[i][i+1] = (s[i]==s[i+1] ? 1 : 0) -- for odd/even
// f[i][j]=(s[i]==s[j] ? f[i+1][j-1] : 0);
// class Solution {
// public:
//   int countSubstrings(string s) {
//     vector<vector<int>> f(s.size(), vector<int>(s.size()));
//     int res = 0;
//     for (int i = s.size() - 1; i >= 0; --i) {
//       for (int j = i; j < s.size(); ++j) {
//         if (i == j) {
//           f[i][j] = 1;
//         } else if (i + 1 == j) {
//           f[i][j] = (s[i] == s[j] ? 1 : 0);
//         } else {
//           f[i][j] = (s[i] == s[j] ? f[i + 1][j - 1] : 0);
//         }
//         res += f[i][j];
//       }
//     }
//     return res;
//   }
// };

// Recursion w/ memoization O(n^2), O(n^2)
// class Solution {
// public:
//   int countSubstrings(string s) {
//     vector<vector<int>> st(s.size(), vector<int>(s.size(), -1));
//     int cnt = 0;
//     for (int i = 0; i < s.size(); ++i) {
//       for (int j = i; j < s.size(); ++j) {
//         cnt += dfs(s, i, j, st);
//       }
//     }
//     return cnt;
//   }
// private:
//   int dfs(string& s, int i , int j, vector<vector<int>>& st) {
//     if (i >= j) return 1;
//     if (st[i][j] >= 0) return st[i][j];
//     return st[i][j] = s[i] == s[j] ? dfs(s, i + 1, j - 1, st) : 0;
//   }
// };
