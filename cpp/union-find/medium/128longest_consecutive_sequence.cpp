/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.25%)
 * Likes:    5839
 * Dislikes: 276
 * Total Accepted:    451.2K
 * Total Submissions: 954.3K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 * 
 * You must write an algorithm that runs in O(n) time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

// @lc code=start
// Hash-table. A number can only be in one link. we put numbers to visit into a
// unordered_set, and each time pick a number and expand the next and prev
// elements from it until it's not consecutive. Then update max length erase them,
// and pick next not visited number. As all numbers will be only visited once,
// it's O(n), O(n);
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> to_visit(nums.begin(), nums.end());

    int res = 0;
    for (int n : nums) {
      if (to_visit.find(n) == to_visit.end()) continue;
      to_visit.erase(n);
      int pre = n - 1, ne = n + 1;
      while (to_visit.find(pre) != to_visit.end()) to_visit.erase(pre--);
      while (to_visit.find(ne) != to_visit.end()) to_visit.erase(ne++);
      res = max(res, ne - pre - 1);
    }
    return res;
  }
};
// @lc code=end

// Union-Find with path compression and size
// class Solution {
// public:
//   int longestConsecutive(vector<int>& nums) {
//     vector<int> p(nums.size()), s(nums.size());
//     for (int i = 0; i < nums.size(); ++i) {
//       p[i] = i;
//       s[i] = 1;
//     }
//     unordered_map<int, int> visited; // map of value and index.
//     for (int i = 0; i < nums.size(); ++i) {
//       if (visited.find(nums[i]) != visited.end()) continue;
//       if (visited.find(nums[i] + 1) != visited.end())
//         merge(i, visited[nums[i] + 1], p, s);
//       if (visited.find(nums[i] - 1) != visited.end())
//         merge(i, visited[nums[i] - 1], p, s);
//       visited[nums[i]] = i;
//     }
//     int res = 0;
//     for (int i = 0; i < s.size(); ++i) res = max(res, s[i]);
//     return res;
//   }
// private:
//   int find(int a, vector<int>& p) {
//     if (p[a] != a) p[a] = find(p[a], p);
//     return p[a];
//   }

//   void merge(int a, int b, vector<int>& p, vector<int>& s) {
//     if (find(a, p) == find(b, p)) return;
//     s[find(b, p)] += s[find(a, p)];
//     p[find(a, p)] = p[find(b, p)];
//   }
// };
