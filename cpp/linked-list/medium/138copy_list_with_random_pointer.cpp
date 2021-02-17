/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (39.81%)
 * Likes:    4751
 * Dislikes: 799
 * Total Accepted:    532.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]'
 *
 * A linked list of length n is given such that each node contains an
 * additional random pointer, which could point to any node in the list, or
 * null.
 * 
 * Construct a deep copy of the list. The deep copy should consist of exactly n
 * brand new nodes, where each new node has its value set to the value of its
 * corresponding original node. Both the next and random pointer of the new
 * nodes should point to new nodes in the copied list such that the pointers in
 * the original list and copied list represent the same list state. None of the
 * pointers in the new list should point to nodes in the original list.
 * 
 * For example, if there are two nodes X and Y in the original list, where
 * X.random --> Y, then for the corresponding two nodes x and y in the copied
 * list, x.random --> y.
 * 
 * Return the head of the copied linked list.
 * 
 * The linked list is represented in the input/output as a list of n nodes.
 * Each node is represented as a pair of [val, random_index] where:
 * 
 * 
 * val: an integer representing Node.val
 * random_index: the index of the node (range from 0 to n-1) that the random
 * pointer points to, or null if it does not point to any node.
 * 
 * 
 * Your code will only be given the head of the original linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [[1,1],[2,1]]
 * Output: [[1,1],[2,1]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: head = [[3,null],[3,0],[3,null]]
 * Output: [[3,null],[3,0],[3,null]]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = []
 * Output: []
 * Explanation: The given linked list is empty (null pointer), so return
 * null.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 1000
 * -10000 <= Node.val <= 10000
 * Node.random is null or is pointing to some node in the linked list.
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// hashmap, O(N), O(N)
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return head;
        auto trav = head;
        Node* dummy = new Node(0);
        auto copy = dummy;
        unordered_map<Node*, Node*> map;

        // First pass, create a copy with correct next links
        while (trav) {
            copy->next = new Node(trav->val);
            copy = copy->next;
            map[trav] = copy;
            trav = trav->next;
        }

        trav = head;
        copy = dummy->next;
        // Second pass, fix random pointers
        while (trav) {
            if (trav->random) copy->random = map[trav->random];
            trav = trav->next;
            copy = copy->next;
        }

        return dummy->next;
    }
};
// @lc code=end

// Modify link, 3 passes. O(N), O(1)
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return head;
        
//         Node* trav = head;
//         Node* copy = nullptr;
//         Node* new_head = nullptr;
        
//         // first pass: insert copy
//         while (trav) {
//             copy = new Node(trav->val);
//             copy->next = trav->next;
//             trav->next = copy;
//             trav = trav->next->next;
//         }
        
//         // second pass: fix random pointer
//         trav = head;
//         while (trav) {
//             if (trav->random)
//                 trav->next->random = trav->random->next;
//             trav = trav->next->next;
//         }
        
//         // third pass: split odd and even list
//         trav = head;
//         copy = head->next;
//         new_head = copy;
//         while (trav) {
//             trav->next = trav->next->next;
//             copy->next = copy->next ? copy->next->next : nullptr;
//             trav = trav->next;
//             copy = copy->next;
//         }
        
//         return new_head;
//     }
// };
