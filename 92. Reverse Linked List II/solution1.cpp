/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (38.48%)
 * Likes:    2372
 * Dislikes: 140
 * Total Accepted:    273.9K
 * Total Submissions: 708.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 *
 * Note: 1 ≤ m ≤ n ≤ length of list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr) {
      return nullptr;
    }

    auto dummyHead = new ListNode(0);
    dummyHead->next = head;

    auto prev = dummyHead;
    for (auto i = 1; i < m; ++i) {
      prev = head;
      head = head->next;
    }

    auto tail = head;
    for (auto i = m; i < n; ++i) {
      tail = tail->next;
    }

    auto temp = tail->next;
    auto res = reverse(head, tail);

    prev->next = res.first;
    res.second->next = temp;

    return dummyHead->next;
  }

 private:
  pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
    auto prev = tail->next;
    auto p = head;

    while (prev != tail) {
      auto temp = p->next;
      p->next = prev;
      prev = p;
      p = temp;
    }

    return {tail, head};
  }
};
// @lc code=end
