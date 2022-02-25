/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (43.34%)
 * Likes:    525
 * Dislikes: 531
 * Total Accepted:    165.9K
 * Total Submissions: 382.6K
 * Testcase Example:
 * '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * Implement the following operations of a stack using queues.
 *
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 *
 *
 * Example:
 *
 *
 * MyStack stack = new MyStack();
 *
 * stack.push(1);
 * stack.push(2);
 * stack.top();   // returns 2
 * stack.pop();   // returns 2
 * stack.empty(); // returns false
 *
 * Notes:
 *
 *
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 *
 *
 */

// @lc code=start
class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) {
    q.push(x);

    auto len = q.size();
    for (auto i = 0; i < len - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    auto val = q.front();
    q.pop();
    return val;
  }

  /** Get the top element. */
  int top() { return q.front(); }

  /** Returns whether the stack is empty. */
  bool empty() { return q.empty(); }

 private:
  queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
