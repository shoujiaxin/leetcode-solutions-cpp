/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    5789
 * Dislikes: 259
 * Total Accepted:    552.4K
 * Total Submissions: 1.7M
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 *
 * The cache is initialized with a positive capacity.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 *
 * Example:
 *
 *
 * LRUCache cache = new LRUCache(2);
 *
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 *
 *
 *
 *
 */

// @lc code=start
struct Node {
  int key;
  int value;

  Node(int k, int v) : key(k), value(v) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : _capacity(capacity) {}

  int get(int key) {
    auto it = _map.find(key);
    if (it == _map.end()) {
      return -1;
    }

    auto value = it->second->value;
    put(key, value);
    return value;
  }

  void put(int key, int value) {
    auto node = Node(key, value);

    auto it = _map.find(key);
    if (it != _map.end()) {
      _cache.erase(it->second);
    } else {
      if (_cache.size() == _capacity) {
        auto last = _cache.back();
        _cache.pop_back();
        _map.erase(last.key);
      }
    }

    _cache.push_front(node);
    _map[key] = _cache.begin();
  }

 private:
  int _capacity;
  list<Node> _cache;
  unordered_map<int, decltype(_cache.begin())> _map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
