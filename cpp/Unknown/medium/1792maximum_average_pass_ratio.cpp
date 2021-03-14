/*
 * @lc app=leetcode id=1792 lang=cpp
 *
 * [1792] Maximum Average Pass Ratio
 *
 * https://leetcode.com/problems/maximum-average-pass-ratio/description/
 *
 * algorithms
 * Medium (37.16%)
 * Likes:    109
 * Dislikes: 32
 * Total Accepted:    3.6K
 * Total Submissions: 9.1K
 * Testcase Example:  '[[1,2],[3,5],[2,2]]\n2'
 *
 * There is a school that has classes of students and each class will be having
 * a final exam. You are given a 2D integer array classes, where classes[i] =
 * [passi, totali]. You know beforehand that in the i^th class, there are
 * totali total students, but only passi number of students will pass the
 * exam.
 * 
 * You are also given an integer extraStudents. There are another extraStudents
 * brilliant students that are guaranteed to pass the exam of any class they
 * are assigned to. You want to assign each of the extraStudents students to a
 * class in a way that maximizes the average pass ratio across all the
 * classes.
 * 
 * The pass ratio of a class is equal to the number of students of the class
 * that will pass the exam divided by the total number of students of the
 * class. The average pass ratio is the sum of pass ratios of all the classes
 * divided by the number of the classes.
 * 
 * Return the maximum possible average pass ratio after assigning the
 * extraStudents students. Answers within 10^-5 of the actual answer will be
 * accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * Output: 0.78333
 * Explanation: You can assign the two extra students to the first class. The
 * average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
 * Output: 0.53485
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= classes.length <= 10^5
 * classes[i].length == 2
 * 1 <= passi <= totali <= 10^5
 * 1 <= extraStudents <= 10^5
 * 
 * 
 */

// @lc code=start
// Greedy, max heap
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        auto profit = [&](double pass, double total) {
            return (pass + 1) / (total + 1) - pass / total;
        };

        double total = 0;
        priority_queue<pair<double, array<int, 2>>> pq;
        for (auto& c : classes) {
            total += static_cast<double>(c[0]) / c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--) {
            auto [profit_add, c] = pq.top();
            pq.pop();
            total += profit_add;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
        }
        return total / classes.size();
    }
};
// @lc code=end

