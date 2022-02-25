/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (38.28%)
 * Likes:    2620
 * Dislikes: 332
 * Total Accepted:    373.4K
 * Total Submissions: 975.2K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Example 1:
 *
 *
 * Input: 1->2
 * Output: false
 *
 * Example 2:
 *
 *
 * Input: 1->2->2->1
 * Output: true
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) {
      return true;
    }

    auto slowPtr = head;
    auto fastPtr = head;
    while (fastPtr->next && fastPtr->next->next) {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next->next;
    }

    // 翻转后半链表
    auto revertedHalf = revertList(slowPtr->next);

    auto p1 = head;
    auto p2 = revertedHalf;
    while (p2) {
      if (p1->val != p2->val) {
        revertList(revertedHalf);
        return false;
      }

      p1 = p1->next;
      p2 = p2->next;
    }

    revertList(revertedHalf);
    return true;
  }

 private:
  ListNode* revertList(ListNode* head) {
    ListNode* pre = nullptr;
    auto cur = head;

    while (cur) {
      auto temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }

    return pre;
  }
};
// @lc code=end
