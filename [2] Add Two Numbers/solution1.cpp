/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.02%)
 * Likes:    6194
 * Dislikes: 1610
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    auto res = new ListNode(0);
    auto p = res;
    auto n = 0;  // 进位

    while (l1 || l2 || n) {
      auto temp = n;
      n = 0;

      if (l1) {
        temp += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        temp += l2->val;
        l2 = l2->next;
      }

      if (temp > 9) {
        n = 1;
        temp -= 10;
      }

      p->next = new ListNode(temp);
      p = p->next;
    }

    return res->next;
  }
};
// @lc code=end
