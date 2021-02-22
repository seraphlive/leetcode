/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 *
 * https://leetcode.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (30.66%)
 * Likes:    889
 * Dislikes: 1585
 * Total Accepted:    201.9K
 * Total Submissions: 658.7K
 * Testcase Example:  '[3,2,1]'
 *
 * Given integer array nums, return the third maximum number in this array. If
 * the third maximum does not exist, return the maximum number.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,2,1]
 * Output: 1
 * Explanation: The third maximum is 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2]
 * Output: 2
 * Explanation: The third maximum does not exist, so the maximum (2) is
 * returned instead.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,3,1]
 * Output: 1
 * Explanation: Note that the third maximum here means the third maximum
 * distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Can you find an O(n) solution?
 */

// @lc code=start
class Solution {
public:
    int nMax(vector<int>& nums, int n)
    {
        set<int> topN;
        for (auto i : nums) {
            topN.insert(i);
            if (topN.size() > n) topN.erase(topN.begin());
        }
        return (topN.size() < n) ? *(topN.rbegin()) : *(topN.begin());
    }

    int thirdMax(vector<int>& nums)
    {
        return nMax(nums, 3);
    }
};
// @lc code=end

