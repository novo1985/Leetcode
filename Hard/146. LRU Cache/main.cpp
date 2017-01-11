#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity){capacity_ = capacity;}

  int get(int key) {
      if (cache_map.find(key) == cache_map.end()) {
        return -1;
      }
      else {
        pair<int, int> temp;
        temp = make_pair(cache_map[key]->first, cache_map[key]->second);
        Cache_list.erase(cache_map[key]);
        Cache_list.push_back(temp);
        // update the iterator of the new inserted pair
        cache_map[key] = --Cache_list.end();
        return cache_map[key]->second;
      }
  }

  void set(int key, int value){
    int num = get(key);
      if(cache_map.size() < capacity_){
        if(num == -1)
        {
          Cache_list.push_back(make_pair(key, value));
          cache_map[key] = --Cache_list.end();
        }
        else{
          cache_map[key]->second = value;
        }
      } else if(cache_map.size() == capacity_){
        if(num == -1){
          cache_map.erase(Cache_list.front().first);
          Cache_list.pop_front();
          Cache_list.push_back(make_pair(key,value));
          cache_map[key] = --Cache_list.end();
        }
        else{
          cache_map[key]->second = value;
        }
      }

  }

private:
  typedef list<pair<int, int>> Cache;
  Cache Cache_list;
  int capacity_;
  unordered_map <int, Cache::iterator> cache_map;
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  LRUCache lru_cache(2);
  lru_cache.set(2,1);
  lru_cache.set(1,1);
  cout << lru_cache.get(2) << endl;
  lru_cache.set(4,1);
  cout << lru_cache.get(1) << endl;
  cout << lru_cache.get(2) << endl;

  return 0;
}
