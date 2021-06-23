/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 *
 * https://leetcode.com/problems/next-greater-node-in-linked-list/description/
 *
 * algorithms
 * Medium (58.37%)
 * Likes:    1498
 * Dislikes: 77
 * Total Accepted:    75.5K
 * Total Submissions: 129.3K
 * Testcase Example:  '[2,1,5]'
 *
 * We are given a linked list with head as the first node.  Let's number the
 * nodes in the list: node_1, node_2, node_3, ... etc.
 *
 * Each node may have a next larger value: for node_i, next_larger(node_i) is
 * the node_j.val such that j > i, node_j.val > node_i.val, and j is the
 * smallest possible choice.  If such a j does not exist, the next larger value
 * is 0.
 *
 * Return an array of integers answer, where answer[i] =
 * next_larger(node_{i+1}).
 *
 * Note that in the example inputs (not outputs) below, arrays such as [2,1,5]
 * represent the serialization of a linked list with a head node value of 2,
 * second node value of 1, and third node value of 5.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: [2,1,5]
 * Output: [5,5,0]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: [2,7,4,3,5]
 * Output: [7,0,5,5,0]
 *
 *
 *
 * Example 3:
 *
 *
 * Input: [1,7,5,1,9,2,5,1]
 * Output: [7,9,9,9,0,5,0,0]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= node.val <= 10^9 for each node in the linked list.
 * The given list has length in the range [0, 10000].
 *
 *
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// monotonic stack.

class Solution {
 public:
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> nums;
    stack<int> st;
    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      while (!st.empty() && nums[i] > nums[st.top()]) {
        res[st.top()] = nums[i];
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};
// @lc code=end
