/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.56%)
 * Likes:    956
 * Dislikes: 87
 * Total Accepted:    374.5K
 * Total Submissions: 859.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 *
 * Example 1:
 *
 *
 * Input: 1->1->2
 * Output: 1->2
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->2->3->3
 * Output: 1->2->3
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
  ListNode* deleteDuplicates(ListNode* head) {
    auto curr = head;

    while (curr && curr->next) {
      if (curr->next->val == curr->val) {
        auto temp = curr->next;
        curr->next = temp->next;

        delete temp;
        temp = nullptr;
      } else {
        curr = curr->next;
      }
    }

    return head;
  }
};
// @lc code=end
