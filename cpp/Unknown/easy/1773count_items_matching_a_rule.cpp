/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 *
 * https://leetcode.com/problems/count-items-matching-a-rule/description/
 *
 * algorithms
 * Easy (89.62%)
 * Likes:    14
 * Dislikes: 5
 * Total Accepted:    7K
 * Total Submissions: 7.8K
 * Testcase Example:  '[["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]]\n' +
  '"color"\n' +
  '"silver"'
 *
 * You are given an array items, where each items[i] = [typei, colori, namei]
 * describes the type, color, and name of the i^th item. You are also given a
 * rule represented by two strings, ruleKey and ruleValue.
 * 
 * The i^th item is said to match the rule if one of the following is
 * true:
 * 
 * 
 * ruleKey == "type" and ruleValue == typei.
 * ruleKey == "color" and ruleValue == colori.
 * ruleKey == "name" and ruleValue == namei.
 * 
 * 
 * Return the number of items that match the given rule.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: items =
 * [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]],
 * ruleKey = "color", ruleValue = "silver"
 * Output: 1
 * Explanation: There is only one item matching the given rule, which is
 * ["computer","silver","lenovo"].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: items =
 * [["phone","blue","pixel"],["computer","silver","phone"],["phone","gold","iphone"]],
 * ruleKey = "type", ruleValue = "phone"
 * Output: 2
 * Explanation: There are only two items matching the given rule, which are
 * ["phone","blue","pixel"] and ["phone","gold","iphone"]. Note that the item
 * ["computer","silver","phone"] does not match.
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= items.length <= 10^4
 * 1 <= typei.length, colori.length, namei.length, ruleValue.length <= 10
 * ruleKey is equal to either "type", "color", or "name".
 * All strings consist only of lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int i_rule = 0;
        if (ruleKey == "type") i_rule = 0;
        if (ruleKey == "color") i_rule = 1;
        if (ruleKey == "name") i_rule = 2;
        int cnt = 0;
        for (auto item : items) {
            if (item[i_rule] == ruleValue) ++cnt;
        }
        return cnt;   
    }
};
// @lc code=end

