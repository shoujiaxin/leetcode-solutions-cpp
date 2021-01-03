/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (42.68%)
 * Likes:    1725
 * Dislikes: 347
 * Total Accepted:    241.1K
 * Total Submissions: 562.6K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 * Example:
 *
 *
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
  ListNode* partition(ListNode* head, int x) {
    auto dummyHead1 = new ListNode(0);
    auto ptr1 = dummyHead1;
    auto dummyHead2 = new ListNode(0);
    auto ptr2 = dummyHead2;

    while (head) {
      if (head->val < x) {
        ptr1->next = head;
        head = head->next;
        ptr1 = ptr1->next;
        ptr1->next = nullptr;
      } else {
        ptr2->next = head;
        head = head->next;
        ptr2 = ptr2->next;
        ptr2->next = nullptr;
      }
    }

    ptr1->next = dummyHead2->next;
    return dummyHead1->next;
  }
};
// @lc code=end
