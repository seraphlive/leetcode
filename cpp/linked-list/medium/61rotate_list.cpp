/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (31.65%)
 * Likes:    2085
 * Dislikes: 1127
 * Total Accepted:    354.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
//  n = k % len
//  n 3
//
//         s        r             f
//  1 ---> 2   X    3 ---> 4 ---> 5
//  ^        (--->)               |
//  | ----------------------------|       

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head) return head;

        auto p = head;
        int len = 0;
        while (p) {
            ++len;
            p = p->next;
        }

        int n = k % len;
        auto fast = head;
        auto slow = head;
        while (fast->next) {
            if (n-- <= 0) slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        auto res = slow->next;
        slow->next = nullptr;
        return res;
    }
};
// @lc code=end

