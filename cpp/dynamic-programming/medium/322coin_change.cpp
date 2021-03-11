/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.29%)
 * Likes:    6196
 * Dislikes: 187
 * Total Accepted:    578.5K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * You may assume that you have an infinite number of each kind of coin.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1,2,5], amount = 11
 * Output: 3
 * Explanation: 11 = 5 + 5 + 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: coins = [1], amount = 0
 * Output: 0
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: coins = [1], amount = 1
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: coins = [1], amount = 2
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */
// O(n*amount) O(amount) DP
// TODO: Revisit after DP learnt
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& c, int a)
    {
        const int MAX = a + 1;
        vector<int> dp(a + 1, MAX);
        dp[0] = 0;
        for (int i = 1; i <= a; ++i) {
            for (int j = 0; j < c.size(); ++j) {
                if (c[j] <= i) dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
        return dp[a] > a ? -1 : dp[a];
    }
};
// @lc code=end

