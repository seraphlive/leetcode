/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (47.36%)
 * Likes:    5304
 * Dislikes: 490
 * Total Accepted:    745.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * Implement the MinStack class:
 * 
 * 
 * MinStack() initializes the stack object.
 * void push(val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * Output
 * [null,null,null,null,-3,null,0,-2]
 * 
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty
 * stacks.
 * At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 * 
 * 
 */

// @lc code=start
// Using two vectors.
class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() : min_(INT_MAX) {}
  
  void push(int val) {
    st.push_back(val);
    min_ = min(min_, val);
    m_st.push_back(min_);
  }
  
  void pop() {
    m_st.pop_back();
    st.pop_back();
    min_ = m_st.empty() ? INT_MAX : m_st.back();
  }
  
  int top() {
    return st.back();
  }
  
  int getMin() {
    return m_st.back();
  }
 private:
  vector<int> st, m_st;
  int min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// Using Linked list.
// class MinStack {
// public:
//   /** initialize your data structure here. */
//   MinStack() {}
  
//   void push(int val) {
//     if (!head) {
//       head = new Node(val, val);
//     } else {
//       head = new Node(val, min(val, head->min), head);
//     }
//   }
  
//   void pop() {
//     auto t = head;
//     head = head->next;
//     delete t;
//     t = nullptr;
//   }
  
//   int top() {
//     return head->val;
//   }
  
//   int getMin() {
//     return head->min;
//   }
// private:
//   struct Node {
//     int val, min;
//     Node* next;
//     Node(int v, int m) : val(v), min(m), next(nullptr) {}
//     Node(int v, int m, Node* ne) : val(v), min(m), next(ne) {}
//   };
//   Node* head = nullptr;
// };
