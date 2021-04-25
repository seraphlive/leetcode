/*
 * @lc app=leetcode id=1839 lang=cpp
 *
 * [1839] Longest Substring Of All Vowels in Order
 *
 * https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    58
 * Dislikes: 4
 * Total Accepted:    5.3K
 * Total Submissions: 11.4K
 * Testcase Example:  '"aeiaaioaaaaeiiiiouuuooaauuaeiu"'
 *
 * A string is considered beautiful if it satisfies the following
 * conditions:
 * 
 * 
 * Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least
 * once in it.
 * The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's,
 * all 'e's before 'i's, etc.).
 * 
 * 
 * For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful,
 * but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
 * 
 * Given a string word consisting of English vowels, return the length of the
 * longest beautiful substring of word. If no such substring exists, return 0.
 * 
 * A substring is a contiguous sequence of characters in a string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
 * Output: 13
 * Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of
 * length 13.
 * 
 * Example 2:
 * 
 * 
 * Input: word = "aeeeiiiioooauuuaeiou"
 * Output: 5
 * Explanation: The longest beautiful substring in word is "aeiou" of length
 * 5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "a"
 * Output: 0
 * Explanation: There is no beautiful substring, so return 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 5 * 10^5
 * word consists of characters 'a', 'e', 'i', 'o', and 'u'.
 * 
 * 
 */

// @lc code=start
// O(n). When the iteration of j break (whether good substr or not),
// there is no other valid 'a's before j. So on line 17 i continues going from j.
class Solution {
public:
    int longestBeautifulSubstring(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != 'a') continue;
            int j = i + 1;
            int check = 'a';
            while (j < s.size()) {
                if (s[j] < s[j - 1]) break;
                if (s[j] > s[j - 1]) check += s[j];
                ++j;
            }
            if (check == 'a' + 'e' + 'i' + 'o' + 'u')
                res = max(res, j - i);
            i = j - 1;
        }
        return res;
    }
};
// @lc code=end

