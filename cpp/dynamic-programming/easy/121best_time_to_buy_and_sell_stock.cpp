/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (51.71%)
 * Likes:    7915
 * Dislikes: 350
 * Total Accepted:    1.2M
 * Total Submissions: 2.4M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 * 
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 * 
 * 
 */
// k = 1
// p_-110 = 0; p_-111 = INT_MIN;
// p_i10 = max(p_i-110, p_i-111 + prices[i])
// p_i11 = max(p_i-111, p_i-100 - prices[i])= max(p_i-111, -prices[i])
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int p_i10 = 0;
        int p_i11 = INT_MIN;
        for (int price : prices) {
            p_i10 = max(p_i10, p_i11 + price);
            p_i11 = max(p_i11, -price);
        }
        return p_i10;
    }
};
// @lc code=end

