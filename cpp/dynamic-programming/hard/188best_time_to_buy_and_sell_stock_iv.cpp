/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (29.85%)
 * Likes:    2311
 * Dislikes: 134
 * Total Accepted:    175.1K
 * Total Submissions: 586.8K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * You are given an integer array prices where prices[i] is the price of a
 * given stock on the i^th day, and an integer k.
 * 
 * Find the maximum profit you can achieve. You may complete at most k
 * transactions.
 * 
 * Note: You may not engage in multiple transactions simultaneously (i.e., you
 * must sell the stock before you buy again).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 2, prices = [2,4,1]
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 2, prices = [3,2,6,5,0,3]
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
 * profit = 3-0 = 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// @lc code=start
// optimization: 2 days => 1 transaction, so for n days, at most n/2 transactions.
// if k >= n/2, k === +INF
// O(kn), O(k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (k >= prices.size() / 2) {
            int p_ik0 = 0;
            int p_ik1 = INT_MIN;
            for (int price : prices) {
                int p_ik0_old = p_ik0;
                p_ik0 = max(p_ik0, p_ik1 + price);
                p_ik1 = max(p_ik1, p_ik0_old - price);
            }
            return p_ik0;
        }
        else {
            vector<int> p_ik0(k + 1, 0);
            vector<int> p_ik1(k + 1, INT_MIN);
            for (int price : prices) {
                for (int j = 1; j < k + 1; ++j) {
                    p_ik0[j] = max(p_ik0[j], p_ik1[j] + price);
                    p_ik1[j] = max(p_ik1[j], p_ik0[j - 1] - price);
                }
            }
            return p_ik0[k];
        }
    }
};
// @lc code=end

