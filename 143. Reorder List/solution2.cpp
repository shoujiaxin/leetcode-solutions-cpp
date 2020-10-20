/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    2521
 * Dislikes: 129
 * Total Accepted:    280.8K
 * Total Submissions: 712K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 * Example 1:
 *
 *
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 *
 * Example 2:
 *
 *
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr) {
      return;
    }

    auto mid = middleNode(head);
    auto l1 = head;
    auto l2 = mid->next;
    mid->next = nullptr;

    l2 = reverseList(l2);

    mergeList(l1, l2);
  }

 private:
  ListNode* middleNode(ListNode* head) {
    auto fast = head;
    auto slow = head;

    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    return slow;
  }

  ListNode* reverseList(ListNode* head) {
    decltype(head) pre = nullptr;
    auto cur = head;

    while (cur) {
      auto temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }

    return pre;
  }

  void mergeList(ListNode* l1, ListNode* l2) {
    while (l1 && l2) {
      auto temp1 = l1->next;
      auto temp2 = l2->next;

      l1->next = l2;
      l1 = temp1;

      l2->next = l1;
      l2 = temp2;
    }
  }
};
// @lc code=end
