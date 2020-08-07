/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (26.99%)
 * Likes:    508
 * Dislikes: 1429
 * Total Accepted:    187.3K
 * Total Submissions: 684.4K
 * Testcase Example:  '"0.1"\n"1.1"'
 *
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 *
 * You may assume that the version strings are non-empty and contain only
 * digits and the . character.
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 * You may assume the default revision number for each level of a version
 * number to be 0. For example, version number 3.4 has a revision number of 3
 * and 4 for its first and second level revision number. Its third and fourth
 * level revision number are both 0.
 *
 *
 *
 * Example 1:
 *
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 *
 * Example 2:
 *
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 *
 * Example 3:
 *
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 *
 * Example 4:
 *
 * Input: version1 = "1.01", version2 = "1.001"
 * Output: 0
 * Explanation: Ignoring leading zeroes, both “01” and “001" represent the same
 * number “1”
 *
 * Example 5:
 *
 * Input: version1 = "1.0", version2 = "1.0.0"
 * Output: 0
 * Explanation: The first version number does not have a third level revision
 * number, which means its third level revision number is default to "0"
 *
 *
 *
 * Note:
 *
 * Version strings are composed of numeric strings separated by dots . and this
 * numeric strings may have leading zeroes.
 * Version strings do not start or end with dots, and they will not be two
 * consecutive dots.
 *
 */

// @lc code=start

class Version {
  friend bool operator==(const Version &, const Version &);
  friend bool operator<(const Version &, const Version &);
  friend bool operator>(const Version &, const Version &);

 public:
  Version(const string &str) {
    auto begin = 0;
    auto end = 0;

    for (; end < str.size(); ++end) {
      if (str[end] == '.') {
        numbers.push_back(stoi(str.substr(begin, end - begin)));
        begin = end + 1;
      }
    }
    numbers.push_back(stoi(str.substr(begin, end - begin)));
  }

 private:
  vector<int> numbers;
};

bool operator==(const Version &lhs, const Version &rhs) {
  auto l_numbers = lhs.numbers;
  auto r_numbers = rhs.numbers;

  auto size = max(l_numbers.size(), r_numbers.size());
  if (l_numbers.size() < size) {
    l_numbers.resize(size);
  }
  if (r_numbers.size() < size) {
    r_numbers.resize(size);
  }

  auto l_it = l_numbers.cbegin();
  auto r_it = r_numbers.cbegin();

  while (l_it != l_numbers.cend()) {
    if (*l_it != *r_it) {
      return false;
    }
    ++l_it;
    ++r_it;
  }

  return true;
}

bool operator<(const Version &lhs, const Version &rhs) {
  // 拷贝数据成员，用于修改长度
  auto l_numbers = lhs.numbers;
  auto r_numbers = rhs.numbers;

  // 统一长度，较短的补 0，便于比较
  auto size = max(l_numbers.size(), r_numbers.size());
  if (l_numbers.size() < size) {
    l_numbers.resize(size);
  }
  if (r_numbers.size() < size) {
    r_numbers.resize(size);
  }

  auto l_it = l_numbers.cbegin();
  auto r_it = r_numbers.cbegin();

  while (l_it != l_numbers.cend()) {
    if (*l_it < *r_it) {
      return true;
    } else if (*l_it > *r_it) {
      return false;
    } else {
      // 当前位相等，继续比较下一位
      ++l_it;
      ++r_it;
    }
  }

  return false;  // 两个版本号相同
}

bool operator>(const Version &lhs, const Version &rhs) {
  return !(lhs < rhs || lhs == rhs);
}

class Solution {
 public:
  int compareVersion(string version1, string version2) {
    auto ver1 = Version(version1);
    auto ver2 = Version(version2);

    if (ver1 > ver2) {
      return 1;
    } else if (ver1 < ver2) {
      return -1;
    }
    return 0;
  }
};
// @lc code=end
