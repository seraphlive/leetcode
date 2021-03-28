/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (47.50%)
 * Likes:    219
 * Dislikes: 704
 * Total Accepted:    28.4K
 * Total Submissions: 59.3K
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 * 
 * Note:
 * 
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "owoztneoer"
 * 
 * Output: "012"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "fviefuro"
 * 
 * Output: "45"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string originalDigits(string s)
    {
        if (s.empty()) return "";
        unordered_map<char, int> cnt;
        for (auto c : s) ++cnt[c];
        array<int, 10> nums;
        // every even digit contains unique letter not existing in other digits
        nums[0] = cnt['z']; // zero
        nums[2] = cnt['w']; // two
        nums[4] = cnt['u']; // four
        nums[6] = cnt['x']; // six
        nums[8] = cnt['g']; // eight
        // for odd digit, use its unique letter, but deduct even digits already counted
        nums[7] = cnt['s'] - nums[6]; // seven
        nums[3] = cnt['h'] - nums[8]; // three
        nums[5] = cnt['v'] - nums[7]; // five
        nums[1] = cnt['o'] - nums[0] - nums[2] - nums[4]; // one
        nums[9] = cnt['i'] - nums[5] - nums[6] - nums[8]; // nine

        string res;
        for (int i = 0; i < 10; ++i) {
            res += string(nums[i], '0' + i);
        }
        return res;
    }
};
// @lc code=end

