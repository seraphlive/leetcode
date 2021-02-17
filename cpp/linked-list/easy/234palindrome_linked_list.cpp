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
        ListNode* prev = nullptr;
        auto slow = head;
        auto fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            auto tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        if (fast) slow = slow->next;

        // Reverse back while comparing if original list required not to be changed.
        while (slow && prev) {
            if (slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};
// @lc code=end

