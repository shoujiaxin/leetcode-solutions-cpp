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
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    }

    auto result = l1->val < l2->val ? l1 : l2;
    auto q = l1->val < l2->val ? l2 : l1;
    auto curr = result;
    auto pre = curr->next;

    while (pre && q) {
      if (pre->val > q->val) {
        curr->next = q;
        q = q->next;
        curr->next->next = pre;

        curr = curr->next;
      } else {
        curr = pre;
        pre = pre->next;
      }
    }

    if (q) {
      curr->next = q;
    }

    return result;
  }
};
// @lc code=end
