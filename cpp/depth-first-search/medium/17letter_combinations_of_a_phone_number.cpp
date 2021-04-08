/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (49.46%)
 * Likes:    5690
 * Dislikes: 510
 * Total Accepted:    796.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: digits = ""
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: digits = "2"
 * Output: ["a","b","c"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 * 
 * 
 */

// @lc code=start
// DFS
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) return {};

        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a', 'b', 'c'};
        d[3] = {'d', 'e', 'f'};
        d[4] = {'g', 'h', 'i'};
        d[5] = {'j', 'k', 'l'};
        d[6] = {'m', 'n', 'o'};
        d[7] = {'p', 'q', 'r', 's'};
        d[8] = {'t', 'u', 'v'};
        d[9] = {'w', 'x', 'y', 'z'};
        string cur;
        vector<string> ans;
        dfs(digits, d, 0, cur, ans);
        return ans;
    }
private:
    void dfs(const string& digits, const vector<vector<char>>& d, int l, string& cur, vector<string>& ans)
    {
        if (l == digits.size()) {
            ans.push_back(cur);
            return;
        }

        for (const char c : d[digits[l] - '0']) {
            cur.push_back(c);
            dfs(digits, d, l + 1, cur, ans);
            cur.pop_back();
        }
    }
};
// @lc code=end

// BFS
// class Solution {
// public:
//     vector<string> letterCombinations(string digits)
//     {
//         if (digits.empty()) return {};

//         vector<vector<char>> d(10);
//         d[0] = {' '};
//         d[1] = {};
//         d[2] = {'a', 'b', 'c'};
//         d[3] = {'d', 'e', 'f'};
//         d[4] = {'g', 'h', 'i'};
//         d[5] = {'j', 'k', 'l'};
//         d[6] = {'m', 'n', 'o'};
//         d[7] = {'p', 'q', 'r', 's'};
//         d[8] = {'t', 'u', 'v'};
//         d[9] = {'w', 'x', 'y', 'z'};
//         vector<string> ans{""};

//         for (char digit : digits) {
//             vector<string> tmp;
//             for (const string& s : ans) {
//                 for (char c : d[digit - '0']) tmp.push_back(s + c);
//             }
//             ans.swap(tmp);
//         }
//         return ans;
//     }
// };
