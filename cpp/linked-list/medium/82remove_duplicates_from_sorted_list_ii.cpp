/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (39.95%)
 * Likes:    3077
 * Dislikes: 129
 * Total Accepted:    338.8K
 * Total Submissions: 847.9K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
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
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(-2e9);
    dummy.next = head;
    auto pre = &dummy;
    auto cur = head;

    while (cur && cur->next) {
      if (cur->val == cur->next->val) {
        auto t = cur;
        while (cur && cur->next && cur->val == cur->next->val) {
          cur = cur->next;
        }
        cur = cur->next;
        pre->next = cur;
        // delete/free through t.
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    return dummy.next;
  }
};
// @lc code=end

