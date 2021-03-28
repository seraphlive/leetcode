/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 *
 * https://leetcode.com/problems/number-of-different-integers-in-a-string/description/
 *
 * algorithms
 * Easy (36.60%)
 * Likes:    39
 * Dislikes: 5
 * Total Accepted:    5.8K
 * Total Submissions: 15.9K
 * Testcase Example:  '"a123bc34d8ef34"'
 *
 * You are given a string word that consists of digits and lowercase English
 * letters.
 * 
 * You will replace every non-digit character with a space. For example,
 * "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with
 * some integers that are separated by at least one space: "123", "34", "8",
 * and "34".
 * 
 * Return the number of different integers after performing the replacement
 * operations on word.
 * 
 * Two integers are considered different if their decimal representations
 * without any leading zeros are different.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "a123bc34d8ef34"
 * Output: 3
 * Explanation: The three different integers are "123", "34", and "8". Notice
 * that "34" is only counted once.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word = "leet1234code234"
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "a1b01c001"
 * Output: 1
 * Explanation: The three integers "1", "01", and "001" all represent the same
 * integer because
 * the leading zeros are ignored when comparing their decimal values.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 1000
 * word consists of digits and lowercase English letters.
 * 
 * 
 */

// @lc code=start
// hashset, two-pointers
class Solution {
public:
    int numDifferentIntegers(string word)
    {
        unordered_set<string> nums;
        for (int i = 0; i < word.size(); ++i) {
            if (!isdigit(word[i])) continue;
            string s;
            int j = i;
            while (j < word.size() && isdigit(word[j])) s += word[j++];
            int k = 0;
            while (k + 1 < word.size() && s[k] == '0') ++k;
            nums.insert(s.substr(k));
            i = j;
        }
        return nums.size();
    }
};
// @lc code=end

