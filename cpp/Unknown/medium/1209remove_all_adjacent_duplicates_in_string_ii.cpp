/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 *
 * https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
 *
 * algorithms
 * Medium (57.78%)
 * Likes:    1237
 * Dislikes: 30
 * Total Accepted:    75.2K
 * Total Submissions: 130.1K
 * Testcase Example:  '"abcd"\n2'
 *
 * Given a string s, a k duplicate removal consists of choosing k adjacent and
 * equal letters from s and removing them causing the left and the right side
 * of the deleted substring to concatenate together.
 * 
 * We repeatedly make k duplicate removals on s until we no longer can.
 * 
 * Return the final string after all such duplicate removals have been made.
 * 
 * It is guaranteed that the answer is unique.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcd", k = 2
 * Output: "abcd"
 * Explanation: There's nothing to delete.
 * 
 * Example 2:
 * 
 * 
 * Input: s = "deeedbbcccbdaa", k = 3
 * Output: "aa"
 * Explanation: 
 * First delete "eee" and "ccc", get "ddbbbdaa"
 * Then delete "bbb", get "dddaa"
 * Finally delete "ddd", get "aa"
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pbbcggttciiippooaais", k = 2
 * Output: "ps"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * 2 <= k <= 10^4
 * s only contains lower case English letters.
 * 
 * 
 */

// @lc code=start
// stack, O(n), O(n).
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> st;
        string res;
        for (auto c : s) {
            if (st.empty() || st.back().first != c) st.push_back({c, 0});
            if (++st.back().second == k) st.pop_back();
        }
        for (auto& p : st) res += string(p.second, p.first);
        return res;
    }
};
// @lc code=end

// two-pointers, O(n), O(n).
// class Solution {
// public:
//     string removeDuplicates(string s, int k)
//     {
//         int j = 0;
//         vector<int> cnt(s.size(), 1);
//         for (int i = 0; i < s.size(); ++i, ++j) {
//             s[j] = s[i];
//             if (j > 0 && s[j] == s[j - 1]) cnt[j] = cnt[j - 1] + 1;
//             else cnt[j] = 1;
//             if (cnt[j] == k) j -=k;
//         }
//         return s.substr(0, j);
//     }
// };

// brute force, O(n^2/k), O(1)
// class Solution {
// public:
//     string removeDuplicates(string s, int k)
//     {
//         bool flag = true;
//         while (flag) {
//             flag = false;
//             int cnt = 1;
//             for (int i = 1; i < s.size() && !flag; ++i) {
//                 if (s[i] != s[i - 1]) cnt = 1;
//                 else if (++cnt == k) {
//                     s = s.substr(0, i - k + 1) + s.substr(i + 1);
//                     flag = true;
//                 }
//             }
//         }
//         return s;
//     }
// };
