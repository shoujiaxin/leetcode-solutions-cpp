/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.47%)
 * Likes:    2782
 * Dislikes: 407
 * Total Accepted:    719.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    auto dummyHead = new ListNode(0);
    auto p = dummyHead;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        l2 = l2->next;
      }
      p = p->next;
    }

    p->next = (l1) ? l1 : l2;

    return dummyHead->next;
  }
};
// @lc code=end
