/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Medium (36.86%)
 * Likes:    4837
 * Dislikes: 946
 * Total Accepted:    708.6K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5,6,7], k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-100,3,99], k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^5
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * Try to come up with as many solutions as you can. There are at least three
 * different ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 * 
 */

// @lc code=start
// Start from first element and keep rotating.
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		int rotated_cnt = 0; // To count elements rotated.
		int start = 0; // Track start point of current round.
		int cur = 0; // Track current position.
		int tmp = nums[0];
		while (rotated_cnt != nums.size()) {
			do {
				swap(tmp, nums[(cur + k) % nums.size()]);
				cur = (cur + k) % nums.size();
				++rotated_cnt;
			} while (cur != start);

			++start;
			cur = start;
			tmp = nums[cur];
		}
	}
};
// @lc code=end

// Use reverse, O(n), O(1)
// class Solution {
// public:
// 	void rotate(vector<int>& nums, int k) {
// 		k %= nums.size();
// 		reverse(nums.begin(), nums.begin() + nums.size() - k);
// 		reverse(nums.begin() + nums.size() - k, nums.end());
// 		reverse(nums.begin(), nums.end());
// 	}
// };

// Copy use extra array, O(n), O(n);
// class Solution {
// public:
// 	void rotate(vector<int>& nums, int k) {
//    k %= nums.size();
// 		vector<int> res(nums.size());

// 		for (int i = 0; i < nums.size(); ++i) res[(i + k) % nums.size()] = nums[i];
// 		nums = res;
// 	}
// };

// brute force right shift 1 step a time. O(nk), O(1). TLE
// class Solution {
// public:
// 	void rotate(vector<int>& nums, int k) {
// 		k %= nums.size();
// 		int tmp, pre;
// 		for (int i = 0; i < k; ++i) {
// 			pre = nums[nums.size() - 1];
// 			for (int j = 0; j < nums.size(); ++j) {
// 				tmp = nums[j];
// 				nums[j] = pre;
// 				pre = tmp;
// 			}
// 		}
// 	}
// };
