/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (57.44%)
 * Likes:    3673
 * Dislikes: 81
 * Total Accepted:    851.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 *
 * Example:
 *
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 *
 *
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
  ListNode* reverseList(ListNode* head) {
    decltype(head) currPtr = nullptr;
    auto nextPtr = head;

    while (nextPtr) {
      auto temp = nextPtr->next;
      nextPtr->next = currPtr;
      currPtr = nextPtr;
      nextPtr = temp;
    }

    return currPtr;
  }
};
// @lc code=end
