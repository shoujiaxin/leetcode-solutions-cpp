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
    l1 = revertList(l1);
    l2 = revertList(l2);

    auto dummyHead = new ListNode(0);
    auto p = dummyHead;

    auto p1 = l1;
    auto p2 = l2;

    while (p1 || p2) {
      auto val = 0;

      if (p1) {
        val += p1->val;
        p1 = p1->next;
      }
      if (p2) {
        val += p2->val;
        p2 = p2->next;
      }

      p->next = new ListNode(val);
      p = p->next;
    }

    p = dummyHead->next;
    while (p) {
      if (p->val > 9) {
        p->val -= 10;
        if (p->next) {
          p->next->val += 1;
        } else {
          p->next = new ListNode(1);
        }
      }

      p = p->next;
    }

    l1 = revertList(l1);
    l2 = revertList(l2);

    return revertList(dummyHead->next);
  }

 private:
  ListNode* revertList(ListNode* head) {
    ListNode* pre = nullptr;
    auto cur = head;

    while (cur) {
      auto temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }

    return pre;
  }
};
// @lc code=end
