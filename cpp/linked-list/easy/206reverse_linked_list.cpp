/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (65.00%)
 * Likes:    6322
 * Dislikes: 122
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
// Iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

// @lc code=end

// Tail Recursive
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head)
//     {
//         return reverse(head, nullptr);
//     }

//     ListNode* reverse(ListNode* head, ListNode* rhead)
//     {
//         if (!head) return rhead;

//         auto next = head->next;
//         head->next = rhead;
//         rhead = head;
//         head = next;

//         return reverse(head, rhead);
//     }
// };
