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

    vector<ListNode*> nodes;
    auto p = head;
    while (p) {
      nodes.push_back(p);
      p = p->next;
    }

    auto l = 0;
    auto r = nodes.size() - 1;
    while (l < r) {
      nodes[l]->next = nodes[r];
      ++l;
      if (l == r) {
        break;
      }
      nodes[r]->next = nodes[l];
      --r;
    }
    nodes[l]->next = nullptr;
  }
};
// @lc code=end
