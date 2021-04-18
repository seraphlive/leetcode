/*
 * @lc app=leetcode id=1830 lang=cpp
 *
 * [1830] Minimum Number of Operations to Make String Sorted
 *
 * https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/description/
 *
 * algorithms
 * Hard (36.83%)
 * Likes:    51
 * Dislikes: 43
 * Total Accepted:    725
 * Total Submissions: 1.9K
 * Testcase Example:  '"cba"'
 *
 * You are given a string s (0-indexed)​​​​​​. You are asked to perform the
 * following operation on s​​​​​​ until you get a sorted string:
 * 
 * 
 * Find the largest index i such that 1 <= i < s.length and s[i] < s[i -
 * 1].
 * Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for
 * all the possible values of k in the range [i, j] inclusive.
 * Swap the two characters at indices i - 1​​​​ and j​​​​​.
 * Reverse the suffix starting at index i​​​​​​.
 * 
 * 
 * Return the number of operations needed to make the string sorted. Since the
 * answer can be too large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cba"
 * Output: 5
 * Explanation: The simulation goes as follows:
 * Operation 1: i=2, j=2. Swap s[1] and s[2] to get s="cab", then reverse the
 * suffix starting at 2. Now, s="cab".
 * Operation 2: i=1, j=2. Swap s[0] and s[2] to get s="bac", then reverse the
 * suffix starting at 1. Now, s="bca".
 * Operation 3: i=2, j=2. Swap s[1] and s[2] to get s="bac", then reverse the
 * suffix starting at 2. Now, s="bac".
 * Operation 4: i=1, j=1. Swap s[0] and s[1] to get s="abc", then reverse the
 * suffix starting at 1. Now, s="acb".
 * Operation 5: i=2, j=2. Swap s[1] and s[2] to get s="abc", then reverse the
 * suffix starting at 2. Now, s="abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabaa"
 * Output: 2
 * Explanation: The simulation goes as follows:
 * Operation 1: i=3, j=4. Swap s[2] and s[4] to get s="aaaab", then reverse the
 * substring starting at 3. Now, s="aaaba".
 * Operation 2: i=4, j=4. Swap s[3] and s[4] to get s="aaaab", then reverse the
 * substring starting at 4. Now, s="aaaab".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "cdbea"
 * Output: 63
 * 
 * Example 4:
 * 
 * 
 * Input: s = "leetcodeleetcodeleetcode"
 * Output: 982157772
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3000
 * s​​​​​​ consists only of lowercase English letters.
 * 
 * 
 */
// 排列的排名, 火星人, 快速幂求逆元, 康托展开/数位DP
// @lc code=start
using LL = long long;
const int MOD = 1e9 + 7;
const int N = 3010;

class Solution {
public:
    int makeStringSorted(string s)
    {
        f[0] = g[0] = 1;
        for (int i = 1; i < s.size(); ++i) {
            f[i] = f[i - 1] * i % MOD;
            g[i] = qmi(f[i], MOD - 2);
        }
        int res = 0;
        int cnt[26] = {0};
        for (auto c : s) ++cnt[c - 'a'];
        for (auto c : s) {
            int x = c - 'a';
            for (int i = 0; i < x; ++i) {
                if (!cnt[i]) continue;
                --cnt[i];
                res = (res + get(cnt)) % MOD;
                ++cnt[i];
            }
            --cnt[x];
        }
        return res;
    }
private:
    LL f[N], g[N];

    LL qmi(LL a, int b)
    {
        LL res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int get(int cnt[])
    {
        int sum = 0;
        for (int i = 0; i < 26; ++i) sum += cnt[i];
        int res = f[sum];
        for (int i = 0; i < 26; ++i) res = static_cast<LL>(res) * g[cnt[i]] % MOD;
        return res;
    }
};
// @lc code=end

