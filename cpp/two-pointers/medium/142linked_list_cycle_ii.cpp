/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (39.48%)
 * Likes:    3769
 * Dislikes: 283
 * Total Accepted:    416.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to. Note that pos is not passed as a parameter.
 * 
 * Notice that you should not modify the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 * 
 * 
 * 
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// based on 141
class Solution {
public:
    ListNode* hasCycle(ListNode* head)
    {
        auto fast = head;
        auto slow = head;
        while (fast) {
            if (!fast->next) return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return slow;
        }
        return nullptr;
    }

    ListNode* detectCycle(ListNode* head)
    {
        auto x = hasCycle(head);
        if (!x) return NULL;
        else
        {
            auto slow = head;
            auto fast = x;
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
};
// @lc code=end

