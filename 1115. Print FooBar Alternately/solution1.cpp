/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 *
 * https://leetcode.com/problems/print-foobar-alternately/description/
 *
 * concurrency
 * Medium (58.12%)
 * Likes:    270
 * Dislikes: 23
 * Total Accepted:    26.6K
 * Total Submissions: 45.4K
 * Testcase Example:  '1'
 *
 * Suppose you are given the following code:
 *
 *
 * class FooBar {
 * ⁠ public void foo() {
 * for (int i = 0; i < n; i++) {
 * print("foo");
 * }
 * ⁠ }
 *
 * ⁠ public void bar() {
 * for (int i = 0; i < n; i++) {
 * print("bar");
 * }
 * ⁠ }
 * }
 *
 *
 * The same instance of FooBar will be passed to two different threads. Thread
 * A will call foo() while thread B will call bar(). Modify the given program
 * to output "foobar" n times.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1
 * Output: "foobar"
 * Explanation: There are two threads being fired asynchronously. One of them
 * calls foo(), while the other calls bar(). "foobar" is being output 1 time.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2
 * Output: "foobarfoobar"
 * Explanation: "foobar" is being output 2 times.
 *
 *
 */

// @lc code=start
class FooBar {
 private:
  int n;
  mutex m1;
  mutex m2;

 public:
  FooBar(int n) {
    this->n = n;
    m2.lock();
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      m1.lock();

      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();

      m2.unlock();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      m2.lock();

      // printBar() outputs "bar". Do not change or remove this line.
      printBar();

      m1.unlock();
    }
  }
};
// @lc code=end
