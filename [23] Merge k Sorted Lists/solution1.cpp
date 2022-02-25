/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (38.39%)
 * Likes:    3883
 * Dislikes: 252
 * Total Accepted:    564.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 *
 * Example:
 *
 *
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }

    if (lists.size() == 1) {
      return lists.front();
    } else if (lists.size() == 2) {
      return mergeTwoLists(lists[0], lists[1]);
    }

    auto mid = lists.size() / 2;
    auto leftSub = vector<ListNode*>(lists.begin(), lists.begin() + mid);
    auto rightSub = vector<ListNode*>(lists.begin() + mid, lists.end());

    return mergeTwoLists(mergeKLists(leftSub), mergeKLists(rightSub));
  }

 private:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    auto dummyHead = new ListNode(0);
    auto p = dummyHead;

    while (l1 || l2) {
      if (l1 && l2) {
        if (l1->val < l2->val) {
          p->next = l1;
          l1 = l1->next;
        } else {
          p->next = l2;
          l2 = l2->next;
        }
        p = p->next;
      } else {
        p->next = (l1) ? l1 : l2;
        break;
      }
    }

    return dummyHead->next;
  }
};
// @lc code=end
