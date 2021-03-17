/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (40.03%)
 * Likes:    3334
 * Dislikes: 86
 * Total Accepted:    280.4K
 * Total Submissions: 700.4K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * Find the maximum profit you can achieve. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are engaging multiple transactions at the same time. You must sell before
 * buying again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 * Example 4:
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
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^5
 * 
 * 
 */

// @lc code=start
// k = 2
// p_i20 = max(p_i-120, p_i-121 + price[i])
// p_i21 = max(p_i-121, p_i-110 - price[i])
// p_i10 = max(p_i-110, p_i-111 + price[i])
// p_i11 = max(p_i-111, p_i-100 - price[i]) = max(p_i-111, -price[i])
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int p_i10 = 0;
        int p_i20 = 0;
        int p_i11 = INT_MIN;
        int p_i21 = INT_MIN;
        for (int price : prices) {
            p_i20 = max(p_i20, p_i21 + price);
            p_i21 = max(p_i21, p_i10 - price);
            p_i10 = max(p_i10, p_i11 + price);
            p_i11 = max(p_i11, -price);
        }
        return p_i20;
    }
};
// @lc code=end

