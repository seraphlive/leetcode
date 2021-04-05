/*
 * @lc app=leetcode id=1815 lang=cpp
 *
 * [1815] Maximum Number of Groups Getting Fresh Donuts
 *
 * https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/description/
 *
 * algorithms
 * Hard (28.77%)
 * Likes:    67
 * Dislikes: 8
 * Total Accepted:    1.2K
 * Total Submissions: 3.9K
 * Testcase Example:  '3\n[1,2,3,4,5,6]'
 *
 * There is a donuts shop that bakes donuts in batches of batchSize. They have
 * a rule where they must serve all of the donuts of a batch before serving any
 * donuts of the next batch. You are given an integer batchSize and an integer
 * array groups, where groups[i] denotes that there is a group of groups[i]
 * customers that will visit the shop. Each customer will get exactly one
 * donut.
 * 
 * When a group visits the shop, all customers of the group must be served
 * before serving any of the following groups. A group will be happy if they
 * all get fresh donuts. That is, the first customer of the group does not
 * receive a donut that was left over from the previous group.
 * 
 * You can freely rearrange the ordering of the groups. Return the maximum
 * possible number of happy groups after rearranging the groups.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: batchSize = 3, groups = [1,2,3,4,5,6]
 * Output: 4
 * Explanation: You can arrange the groups as [6,2,4,5,1,3]. Then the 1^st,
 * 2^nd, 4^th, and 6^th groups will be happy.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: batchSize = 4, groups = [1,3,2,5,2,2,1,6]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= batchSize <= 9
 * 1 <= groups.length <= 30
 * 1 <= groups[i] <= 10^9
 * 
 * 
 */

// @lc code=start
// Simulated annealing + parameter tuning.
class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups)
    {
        w = groups;
        n = w.size();
        m = batchSize;
        ans = 0;
        
        for (int i = 0; i < 80; ++i) simulated_annealing();
        return ans;
    }
private:
    int n, m;
    vector<int> w;
    int ans;

    int calc()
    {
        int res = 1;
        for (int i = 0, s = 0; i < n; ++i) {
            s = (s + w[i]) % m;
            if (!s && i < n - 1) ++res;
        }
        ans = max(ans, res);
        return res;
    }

    void simulated_annealing()
    {
        random_shuffle(w.begin(), w.end());

        for (double t = 1e6; t > 1e-5; t *= 0.97) {
            int a = rand() % n;
            int b = rand() % n;
            int x = calc();
            swap(w[a], w[b]);
            int y = calc();
            int delta = x - y;
            if (!(exp(-delta / t) > (double)rand() / RAND_MAX))
                swap(w[a], w[b]);
        }
    }
};
// @lc code=end

