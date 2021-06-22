/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (53.41%)
 * Likes:    1860
 * Dislikes: 169
 * Total Accepted:    288.1K
 * Total Submissions: 538.9K
 * Testcase Example:  '["MyQueue","push","push","peek","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement a first in first out (FIFO) queue using only two stacks. The
 * implemented queue should support all the functions of a normal queue (push,
 * peek, pop, and empty).
 * 
 * Implement the MyQueue class:
 * 
 * 
 * void push(int x) Pushes element x to the back of the queue.
 * int pop() Removes the element from the front of the queue and returns
 * it.
 * int peek() Returns the element at the front of the queue.
 * boolean empty() Returns true if the queue is empty, false otherwise.
 * 
 * 
 * Notes:
 * 
 * 
 * You must use only standard operations of a stack, which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, the stack may not be supported natively. You may
 * simulate a stack using a list or deque (double-ended queue) as long as you
 * use only a stack's standard operations.
 * 
 * 
 * Follow-up: Can you implement the queue such that each operation is amortized
 * O(1) time complexity? In other words, performing n operations will take
 * overall O(n) time even if one of those operations may take longer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MyQueue", "push", "push", "peek", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * Output
 * [null, null, null, 1, 1, false]
 * 
 * Explanation
 * MyQueue myQueue = new MyQueue();
 * myQueue.push(1); // queue is: [1]
 * myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
 * myQueue.peek(); // return 1
 * myQueue.pop(); // return 1, queue is [2]
 * myQueue.empty(); // return false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= x <= 9
 * At most 100 calls will be made to push, pop, peek, and empty.
 * All the calls to pop and peek are valid.
 * 
 * 
 */

// @lc code=start
// Use in stack to store the queue. When popping, move data to the out stack,
// pop the top value and move back. naive. pop and push are both O(n);
//
// Use stack 2 as cache and insert in correct queue order when push: push is O(n)
// and pop is O(1).
//
// Best: stack 1 in, stack 2 out. Push directly into in stack, so O(1) pushing.
// Keep record of front element of in stack, so O(1) peeking. For poping, if out
// is not empty, pop directly from out stack, otherwise move all data from in to
// out then pop. Amortized O(1) poping.
class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() : front_(0) {}
  
  /** Push element x to the back of queue. */
  void push(int x) {
    if (in.empty()) front_ = x;
    in.push(x);
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (out.empty()) {
      while (!in.empty()) {
        out.push(in.top());
        in.pop();
      }
    }
    int res = out.top();
    out.pop();
    return res;
  }
  
  /** Get the front element. */
  int peek() {
    if (!out.empty()) {
      return out.top();
    } else {
      return front_;
    }
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return in.empty() && out.empty();
  }
private:
  stack<int> in, out;
  int front_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

