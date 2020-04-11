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

    vector<int> vec;

    while (head) {
      vec.push_back(head->val);
      head = head->next;
    }

    auto left = vec.cbegin();
    auto right = vec.cend() - 1;

    while (left < right) {
      if (*left != *right) {
        return false;
      }

      ++left;
      --right;
    }

    return true;
  }
};
// @lc code=end
