/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (40.54%)
 * Likes:    2155
 * Dislikes: 358
 * Total Accepted:    265.8K
 * Total Submissions: 641.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 *
 *
 *
 *
 * Example:
 *
 * Given this linked list: 1->2->3->4->5
 *
 * For k = 2, you should return: 2->1->4->3->5
 *
 * For k = 3, you should return: 3->2->1->4->5
 *
 * Note:
 *
 *
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr) {
      return nullptr;
    }

    auto dummyHead = new ListNode(0);
    dummyHead->next = head;

    auto pre = dummyHead;

    while (head) {
      auto tail = pre;
      for (auto i = 0; i < k; ++i) {
        tail = tail->next;

        // 剩余不足 k 个，不翻转
        if (tail == nullptr) {
          return dummyHead->next;
        }
      }

      auto temp = tail->next;

      auto res = reverseList(head, tail);
      head = res.first;
      tail = res.second;

      // 连接翻转部分和其他部分
      pre->next = head;
      tail->next = temp;

      // 前进到下一组
      pre = tail;
      head = tail->next;
    }

    return dummyHead->next;
  }

 private:
  /// 翻转链表 [head, tail]，返回翻转后的头和尾
  /// @param head 指向待翻转链表的头
  /// @param tail 指向待翻转链表的尾
  pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
    auto pre = tail->next;
    auto p = head;

    while (pre != tail) {
      auto temp = p->next;
      p->next = pre;
      pre = p;
      p = temp;
    }

    return make_pair(tail, head);
  }
};
// @lc code=end
