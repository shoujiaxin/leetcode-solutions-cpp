/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (53.16%)
 * Likes:    1177
 * Dislikes: 140
 * Total Accepted:    138.9K
 * Total Submissions: 261K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 *
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
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stk1;
    while (l1) {
      stk1.push(l1->val);
      l1 = l1->next;
    }

    stack<int> stk2;
    while (l2) {
      stk2.push(l2->val);
      l2 = l2->next;
    }

    auto carry = 0;  // 进位
    ListNode* head = nullptr;

    while (!stk1.empty() || !stk2.empty() || carry != 0) {
      auto val = carry;

      if (!stk1.empty()) {
        val += stk1.top();
        stk1.pop();
      }
      if (!stk2.empty()) {
        val += stk2.top();
        stk2.pop();
      }

      carry = val / 10;
      val %= 10;

      auto node = new ListNode(val);
      node->next = head;
      head = node;
    }

    return head;
  }
};
// @lc code=end
