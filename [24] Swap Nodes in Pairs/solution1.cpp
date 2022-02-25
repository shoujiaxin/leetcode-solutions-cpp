/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.48%)
 * Likes:    1836
 * Dislikes: 155
 * Total Accepted:    419.6K
 * Total Submissions: 864.6K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 *
 *
 *
 * Example:
 *
 *
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
  ListNode* swapPairs(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }

    auto dummyHead = new ListNode(0);
    dummyHead->next = head;
    auto pre = dummyHead;
    auto cur = head;
    auto nxt = cur->next;

    while (nxt) {
      auto temp = nxt->next;
      pre->next = nxt;
      nxt->next = cur;
      cur->next = temp;

      pre = cur;
      cur = cur->next;
      if (!cur) {
        break;
      }
      nxt = cur->next;
    }

    return dummyHead->next;
  }
};
// @lc code=end
