/*
 * @lc app=leetcode id=1803 lang=cpp
 *
 * [1803] Count Pairs With XOR in a Range
 *
 * https://leetcode.com/problems/count-pairs-with-xor-in-a-range/description/
 *
 * algorithms
 * Hard (40.84%)
 * Likes:    99
 * Dislikes: 7
 * Total Accepted:    2.2K
 * Total Submissions: 5.5K
 * Testcase Example:  '[1,4,2,7]\n2\n6'
 *
 * Given a (0-indexed) integer array nums and two integers low and high, return
 * the number of nice pairs.
 * 
 * A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <=
 * (nums[i] XOR nums[j]) <= high.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,4,2,7], low = 2, high = 6
 * Output: 6
 * Explanation: All nice pairs (i, j) are as follows:
 * ⁠   - (0, 1): nums[0] XOR nums[1] = 5 
 * ⁠   - (0, 2): nums[0] XOR nums[2] = 3
 * ⁠   - (0, 3): nums[0] XOR nums[3] = 6
 * ⁠   - (1, 2): nums[1] XOR nums[2] = 6
 * ⁠   - (1, 3): nums[1] XOR nums[3] = 3
 * ⁠   - (2, 3): nums[2] XOR nums[3] = 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [9,8,4,2,1], low = 5, high = 14
 * Output: 8
 * Explanation: All nice pairs (i, j) are as follows:
 * ​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
 * - (0, 3): nums[0] XOR nums[3] = 11
 * - (0, 4): nums[0] XOR nums[4] = 8
 * - (1, 2): nums[1] XOR nums[2] = 12
 * - (1, 3): nums[1] XOR nums[3] = 10
 * - (1, 4): nums[1] XOR nums[4] = 9
 * - (2, 3): nums[2] XOR nums[3] = 6
 * - (2, 4): nums[2] XOR nums[4] = 5
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] <= 2 * 10^4
 * 1 <= low <= high <= 2 * 10^4
 * 
 * 
 */

// @lc code=start
// Trie
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high)
    {
        TrieNode* root = new TrieNode();
        int ans = 0;

        for (int num : nums) {
            // (0, high + 1) - (0, low) = [low, high]
            ans += getCount(root, num, high + 1) - getCount(root, num, low);
            insert(root, num);
        }
        return ans;
    }
private:
    const int HEIGHT = 14; // 1 <= nums[i] <= 20000
    struct TrieNode {
        TrieNode* child[2];
        int cnt;
        TrieNode() : cnt(0), child{nullptr, nullptr} {}
    };

    void insert(TrieNode* root, int num)
    {
        auto curr = root;
        for (int j = HEIGHT; j >= 0; --j) {
            int i = (num >> j) & 1;
            if (!curr->child[i]) curr->child[i] = new TrieNode();
            curr = curr->child[i];
            ++curr->cnt;
        }
    }

    int getCount(TrieNode* root, int num, int limit)
    {
        auto curr = root;
        int cnt = 0;
        for (int j = HEIGHT; j >= 0; --j) {
            int num_bit = (num >> j) & 1;
            int limit_bit = (limit >> j) & 1;

            if (limit_bit == 1) {
                // The paths (if any) under num_bit XOR num_bit
                // which is 0 (< limit_bit = 1) are all satisfying.
                if (curr->child[num_bit]) cnt += curr->child[num_bit]->cnt;
                // Then we go to the other child path
                // which is num_bit XOR ~num_bit = 1 === limit (tied for this layer)
                // and continue checking its next layer.
                curr = curr->child[1 - num_bit];
            }
            else {
                // If limit_bit=0, the XOR result can never be greater than it.
                // So we have to choose num_bit XOR num_bit to get a tie,
                // then go that path to check its next layer.
                curr = curr->child[num_bit];
            }

            if (!curr) break;
        }
        return cnt;
    }
};
// @lc code=end

