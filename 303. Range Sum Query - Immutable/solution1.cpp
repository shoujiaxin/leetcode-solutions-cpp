/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (42.16%)
 * Likes:    734
 * Dislikes: 957
 * Total Accepted:    180.5K
 * Total Submissions: 426.5K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 *
 * Example:
 *
 * Given nums = [-2, 0, 3, -5, 2, -1]
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 *
 *
 * Note:
 *
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 *
 *
 */

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) {
    auto len = nums.size();
    sum = vector<vector<int>>(len, vector<int>(len, 0));

    for (int i = 0; i < len; ++i) {
      sum[i][i] = nums[i];
    }

    for (int i = 0; i < len; ++i) {
      for (int j = i + 1; j < len; ++j) {
        sum[i][j] = sum[i][j - 1] + nums[j];
      }
    }
  }

  int sumRange(int i, int j) { return sum[i][j]; }

 private:
  // sum[i][j] 表示 [i, j] 的和
  vector<vector<int>> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
