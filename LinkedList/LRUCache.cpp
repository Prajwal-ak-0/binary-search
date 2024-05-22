#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;
    
public:
    // Task: The task is to implement a Least Recently Used (LRU) cache. It should be able to support the following operations: get and put.
    // Approach: We use a hash map and a doubly linked list. The hash map makes the time of get() to be O(1). The list of doubly linked nodes make the nodes adding/removal operations O(1).
    // Time Complexity: O(1) for both get and put operations.
    // Space Complexity: O(capacity), the maximum size of the cache.

    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheMap[key]->second = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        } else {
            if (cacheList.size() == capacity) {
                auto lru = cacheList.back();
                cacheMap.erase(lru.first);
                cacheList.pop_back();
            }
            cacheList.emplace_front(key, value);
            cacheMap[key] = cacheList.begin();
        }
    }
};

int main() {
    // Test Case: The cache is initialized with a capacity of 2.
    // put(1, 1), put(2, 2), get(1) should return 1, put(3, 3) should evict key 2, get(2) should return -1, put(4, 4) should evict key 1, get(1) should return -1, get(3) should return 3, and get(4) should return 4.
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << "get(1): " << cache.get(1) << endl;
    cache.put(3, 3);
    cout << "get(2): " << cache.get(2) << endl;
    cache.put(4, 4);
    cout << "get(1): " << cache.get(1) << endl;
    cout << "get(3): " << cache.get(3) << endl;
    cout << "get(4): " << cache.get(4) << endl;

    return 0;
}