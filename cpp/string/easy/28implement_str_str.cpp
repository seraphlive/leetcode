/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (35.11%)
 * Likes:    2163
 * Dislikes: 2255
 * Total Accepted:    822.4K
 * Total Submissions: 2.3M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 * 
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= haystack.length, needle.length <= 5 * 10^4
 * haystack and needle consist of only lower-case English characters.
 * 
 * 
 */

// @lc code=start
// KMP - DFA
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty()) return 0;
        int N = haystack.size();
        int M = needle.size();
        int i = 0;
        int j = 0;
        vector<vector<int>> dfa = construct_dfa(needle);

        while (i < N && j < M) {
            j = dfa[haystack[i]][j];
            ++i;
        }
        if (j == M) return i - M;
        return -1;
    }

private:
    vector<vector<int>> construct_dfa(string pat)
    {
        int M = pat.size();
        int R = 256;
        vector<vector<int>> dfa(R, vector<int>(M));
        dfa[pat[0]][0] = 1;
        int X = 0;

        for (int j = 1; j < M; ++j) {
            for (int c = 0; c < R; ++c) {
                dfa[c][j] = dfa[c][X];
            }
            dfa[pat[j]][j] = j + 1;
            X = dfa[pat[j]][X];
        }
        return dfa;
    }
};
// @lc code=end

// brute force 
// class Solution {
// public:
//     int strStr(string haystack, string needle)
//     {
//         if (needle.empty()) return 0;

//         int M = needle.size();
//         int N = haystack.size();
//         for (int i = 0; i <= N - M; ++i) {
//             int j;
//             for (j = 0; j < M; ++j) {
//                 if (haystack[i + j] != needle[j]) break;
//             }
//             if (j == M) return i;
//         }
//         return -1;
//     }
// };
