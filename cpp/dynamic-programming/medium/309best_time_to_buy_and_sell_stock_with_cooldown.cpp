/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (48.22%)
 * Likes:    3491
 * Dislikes: 112
 * Total Accepted:    187.2K
 * Total Submissions: 388.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * Find the maximum profit you can achieve. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * After you sell your stock, you cannot buy stock on the next day (i.e.,
 * cooldown one day).
 * 
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// @lc code=start
// k = +INF with 1 day cooldown after selling
// new recurrence relation due to the cd time:
// p_ik0=max(p_i-1k0, p_i-1k1 + price[i])
// p_ik1=max(p_i-1k1, p_i-2k0 - price[i])
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int p_ik0 = 0;
        int p_ik0_prepre = 0;
        int p_ik1 = INT_MIN;
        for (int price : prices) {
            int p_ik0_pre = p_ik0;
            p_ik0 = max(p_ik0, p_ik1 + price);
            p_ik1 = max(p_ik1, p_ik0_prepre - price);
            p_ik0_prepre = p_ik0_pre;
        }
        return p_ik0;
    }
};
// @lc code=end

