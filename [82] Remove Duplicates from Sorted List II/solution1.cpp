/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.43%)
 * Likes:    1319
 * Dislikes: 99
 * Total Accepted:    227.2K
 * Total Submissions: 640.8K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 *
 * Return the linked list sorted as well.
 *
 * Example 1:
 *
 *
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 *
 *
 * Example 2:
 *
 *
 * Input: 1->1->1->2->3
 * Output: 2->3
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
    if (!head) {
      return nullptr;
    }

    map<int, int> counter;

    auto ptr = head;
    while (ptr) {
      ++counter[ptr->val];
      ptr = ptr->next;
    }

    ptr = head;
    decltype(ptr) pre = nullptr;
    for (const auto& p : counter) {
      if (p.second == 1) {
        ptr->val = p.first;
        pre = ptr;
        ptr = ptr->next;
      }
    }

    if (pre == nullptr) {
      return nullptr;
    }
    pre->next = nullptr;

    return head;
  }
};
// @lc code=end
