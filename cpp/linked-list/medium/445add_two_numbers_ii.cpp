/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.96%)
 * Likes:    2476
 * Dislikes: 202
 * Total Accepted:    246.9K
 * Total Submissions: 433.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: l1 = [7,2,4,3], l2 = [5,6,4]
 * Output: [7,8,0,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [8,0,7]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 * 
 * 
 * 
 * Follow up: Could you solve it without reversing the input lists?
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
// Use stack to store the values.
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> st1, st2;
    to_stack(l1, st1);
    to_stack(l2, st2);
    ListNode dummy(-1);
    auto p = &dummy;

    int sum = 0;
    while (!st1.empty() || !st2.empty() || sum) {
      int x = 0, y = 0;
      if (!st1.empty()) {
        x = st1.top();
        st1.pop();
      }
      if (!st2.empty()) {
        y = st2.top();
        st2.pop();
      }
      sum += x + y;
      ListNode* node = new ListNode(sum % 10);
      node->next = p->next;
      p->next = node;
      sum /= 10;
    }
    return p->next;
  }
private:
  void to_stack(ListNode* l, stack<int>& st) {
    while (l) {
      st.push(l->val);
      l = l->next;
    }
  }
};
// @lc code=end

