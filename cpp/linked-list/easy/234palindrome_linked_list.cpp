/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.33%)
 * Likes:    4644
 * Dislikes: 423
 * Total Accepted:    557.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    ListNode* pre = nullptr;
    auto fast = head;
    auto slow = head;

    while (fast && fast->next) {
      fast = fast->next->next;
      auto t = slow;
      slow = slow->next;
      t->next = pre;
      pre = t;
    }
    if (fast) slow = slow->next;

    // if it's required not to modify the linked list, set a flag to record the
    // res and reverse the list back during the comparison.
    while (slow && pre) {
      if (slow->val != pre->val) return false;
      pre = pre->next;
      slow = slow->next;
    }
    return true;
  }
};
// @lc code=end

