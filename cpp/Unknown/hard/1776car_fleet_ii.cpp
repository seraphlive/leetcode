/*
 * @lc app=leetcode id=1776 lang=cpp
 *
 * [1776] Car Fleet II
 *
 * https://leetcode.com/problems/car-fleet-ii/description/
 *
 * algorithms
 * Hard (40.33%)
 * Likes:    111
 * Dislikes: 2
 * Total Accepted:    2K
 * Total Submissions: 5K
 * Testcase Example:  '[[1,2],[2,1],[4,3],[7,2]]'
 *
 * There are n cars traveling at different speeds in the same direction along a
 * one-lane road. You are given an array cars of length n, where cars[i] =
 * [positioni, speedi] represents:
 * 
 * 
 * positioni is the distance between the i^th car and the beginning of the road
 * in meters. It is guaranteed that positioni < positioni+1.
 * speedi is the initial speed of the i^th car in meters per second.
 * 
 * 
 * For simplicity, cars can be considered as points moving along the number
 * line. Two cars collide when they occupy the same position. Once a car
 * collides with another car, they unite and form a single car fleet. The cars
 * in the formed fleet will have the same position and the same speed, which is
 * the initial speed of the slowest car in the fleet.
 * 
 * Return an array answer, where answer[i] is the time, in seconds, at which
 * the i^th car collides with the next car, or -1 if the car does not collide
 * with the next car. Answers within 10^-5 of the actual answers are
 * accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: cars = [[1,2],[2,1],[4,3],[7,2]]
 * Output: [1.00000,-1.00000,3.00000,-1.00000]
 * Explanation: After exactly one second, the first car will collide with the
 * second car, and form a car fleet with speed 1 m/s. After exactly 3 seconds,
 * the third car will collide with the fourth car, and form a car fleet with
 * speed 2 m/s.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: cars = [[3,4],[5,4],[6,3],[9,1]]
 * Output: [2.00000,1.00000,1.50000,-1.00000]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= cars.length <= 10^5
 * 1 <= positioni, speedi <= 10^6
 * positioni < positioni+1
 * 
 * 
 */

// @lc code=start
// Mono-stack
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars)
    {
        auto col_time = [&](int i, int j) {
            return (double) (cars[i][0] - cars[j][0]) / (cars[j][1] - cars[i][1]);
        };

        vector<double> res(cars.size(), -1);
        vector<double> stack;

        for (int i = cars.size() - 1; i >= 0; --i) {
            while (!stack.empty() && (cars[i][1] <= cars[stack.back()][1] ||
                                      (stack.size() > 1 && col_time(i, stack.back()) >= res[stack.back()]))) {
                stack.pop_back();
            }
            res[i] = stack.empty() ? -1 : col_time(i, stack.back());
            stack.push_back(i);
        }
        return res;
    }
};

// [[1,2], [2,1], [5,3], [7,2]]
// i=0
// s=[0]
// res=[1.00000, -1.00000,3.00000,-1.00000]                        
// @lc code=end

