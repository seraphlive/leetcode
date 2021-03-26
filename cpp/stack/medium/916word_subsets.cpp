/*
 * @lc app=leetcode id=916 lang=cpp
 *
 * [916] Word Subsets
 *
 * https://leetcode.com/problems/word-subsets/description/
 *
 * algorithms
 * Medium (48.13%)
 * Likes:    513
 * Dislikes: 89
 * Total Accepted:    27K
 * Total Submissions: 55.6K
 * Testcase Example:  '["amazon","apple","facebook","google","leetcode"]\n["e","o"]'
 *
 * We are given two arrays A and B of words.  Each word is a string of
 * lowercase letters.
 * 
 * Now, say that word b is a subset of word a if every letter in b occurs in a,
 * including multiplicity.  For example, "wrr" is a subset of "warrior", but is
 * not a subset of "world".
 * 
 * Now say a word a from A is universal if for every b in B, b is a subset of
 * a. 
 * 
 * Return a list of all universal words in A.  You can return the words in any
 * order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * Output: ["facebook","google","leetcode"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * Output: ["apple","google","leetcode"]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * Output: ["facebook","google"]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["lo","eo"]
 * Output: ["google","leetcode"]
 * 
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: A = ["amazon","apple","facebook","google","leetcode"], B =
 * ["ec","oc","ceo"]
 * Output: ["facebook","leetcode"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length, B.length <= 10000
 * 1 <= A[i].length, B[i].length <= 10
 * A[i] and B[i] consist only of lowercase letters.
 * All words in A[i] are unique: there isn't i != j with A[i] == A[j].
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
// Note: b is sub set not sub sequence.
// For each b, use a counter function to count occurence of each letter in b
// Use the max count of each char among all the bs to filter a.
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B)
    {
        vector<int> count(26);
        vector<int> tmp(26);
        for (auto b : B) {
            tmp = counter(b);
            for (int i = 0; i < 26; ++i)
                count[i] = max(count[i], tmp[i]);
        }
        vector<string> res;
        for (auto a : A) {
            tmp = counter(a);
            int i;
            for (i = 0; i < 26; ++i) {
                if (tmp[i] < count[i]) break;
            }
            if (i == 26) res.push_back(a);
        }
        return res;      
    }
private:
    vector<int> counter(string& word)
    {
        vector<int> cnt(26);
        for (auto c : word) ++cnt[c - 'a'];
        return cnt;
    }
};
// @lc code=end

