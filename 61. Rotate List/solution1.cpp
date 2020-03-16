/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (28.98%)
 * Likes:    930
 * Dislikes: 958
 * Total Accepted:    244.1K
 * Total Submissions: 841.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 *
 *
 * Example 2:
 *
 *
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k == 0) {
      return head;
    }

    int len = 0;

    // 计算链表长度
    auto p1 = head;
    while (p1) {
      ++len;
      p1 = p1->next;
    }

    // 找到倒数第 k + 1 个节点
    p1 = head;
    for (auto i = 0; i < k % len; ++i) {
      p1 = p1->next;
    }

    // k 与链表长度相等，无需旋转
    if (p1 == head) {
      return head;
    }

    auto p2 = head;
    while (p1->next) {
      p2 = p2->next;
      p1 = p1->next;
    }

    // 此时 p2 指向倒数第 k + 1 个节点，即旋转后的最后一个节点
    auto temp = p2->next;
    p2->next = nullptr;
    p1->next = head;

    return temp;
  }
};
// @lc code=end
