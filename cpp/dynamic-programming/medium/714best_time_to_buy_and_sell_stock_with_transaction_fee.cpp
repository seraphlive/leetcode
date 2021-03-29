/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (57.93%)
 * Likes:    2387
 * Dislikes: 71
 * Total Accepted:    103.7K
 * Total Submissions: 179K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day, and an integer fee representing a transaction fee.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like, but you need to pay the transaction fee for each
 * transaction.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,3,2,8,4,9], fee = 2
 * Output: 8
 * Explanation: The maximum profit can be achieved by:
 * - Buying at prices[0] = 1
 * - Selling at prices[3] = 8
 * - Buying at prices[4] = 4
 * - Selling at prices[5] = 9
 * The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1,3,7,5,10,3], fee = 3
 * Output: 6
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 < prices.length <= 5 * 10^4
 * 0 < prices[i], fee < 5 * 10^4
 * 
 * 
 */

// @lc code=start
// k = +INF with transaction fee
// charge the fee on buying. (charge on selling - take care of overflow)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int p_ik0 = 0;
        int p_ik1 = INT_MIN;
        for (int price : prices) {
            int p_ik0_pre = p_ik0;
            p_ik0 = max(p_ik0, p_ik1 + price);
            p_ik1 = max(p_ik1, p_ik0_pre - price - fee);
        }
        return p_ik0;
    }
};
// @lc code=end

