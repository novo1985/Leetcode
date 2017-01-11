#include <iostream>
#include <unordered_map>
#include <list>
#include <sstream>
using namespace std;

class LFUCache {
public:
  LFUCache(int capacity) {
    capacity_ = capacity;
  }
  // once call getter function to get a pair, the pair was used and need update to the back of the cache_list
  // and frequency++
  int get(int key) {
    if(capacity_ == 0){ return -1;}

    if(cache_map.find(key) == cache_map.end()){
      return -1;
    }
    else{
      // step1:increment frequency by 1 and record
      int frequency = ++cache_map[key]->second;

      // step2: delete original pair and save the updated(frequency) copy
      pair<pair<int, int>, int> temp = make_pair(make_pair(key, cache_map[key]->first.second), frequency);
      cache_list.erase(cache_map[key]);

      // step3: we need put the new pair to the last position of same frequency sublist -- find iter position
      auto iter = cache_list.begin();
      while(iter->second <= frequency && iter != cache_list.end()){
        ++iter;
      }

      // step4: update cache_map[] iterator
      cache_map[key] = cache_list.insert(iter,temp);  //insert function return value is iterator
      cout << "get (" << key << "):\n" << CacheToString();
      return cache_map[key]->first.second;
    }
  }

  void put(int key, int value) {
    if(capacity_ == 0) {return;}
    //call the getter function will rearrange list
    int num = get(key);
    //new key insertion
    if(num == -1){
      pair<pair<int, int>, int> temp = make_pair(make_pair(key, value), 1);
      auto iter = cache_list.begin();
      while(iter->second <= temp.second && iter != cache_list.end()){ iter++;}

      if(cache_map.size() < capacity_){
        // insert into the last position of frequency = 1
        cache_map[key] = cache_list.insert(iter,temp);
      }
      else if(cache_map.size() == capacity_){
        // delete the smallest frequency_ pair and least used pair from both list and hash map
        cache_map.erase(cache_list.front().first.first);
        cache_list.pop_front();
        auto iter1 = cache_list.begin();
        while(iter1->second <= temp.second && iter1 != cache_list.end()){ iter1++;}

        //cout << "pop:\n" << CacheToString();
        // already rearrange the position, just insert into the position
        cache_map[key] = cache_list.insert(iter1,temp);
      }
      //cout << "Frequency of Key " << key << " is " << cache_map[key]->second << endl;
    }
    else{
      cache_map[key]->first.second = value;
      //cout << "Frequency of Key " << key << " is " << cache_map[key]->second << endl;
    }

    cout << "put (" << key << ", " << value << "):\n" << CacheToString();
  }

  string CacheToString(void) {
    stringstream ss;

    for (auto &node : cache_list) {
      ss << "key = " << node.first.first
         << " value = " << node.first.second
         << " freq = " << node.second << "\n";
    }

    ss << "\n\n";

    return ss.str();
  }

private:
  typedef list<pair<pair<int, int>, int>> Cache;
  Cache cache_list;
  unordered_map<int, Cache::iterator> cache_map;
  int capacity_;
};
int main() {
  LFUCache test_cache(2);
  test_cache.put(2,2);
  test_cache.put(1,1);
  cout << test_cache.get(2) << endl;
  cout << test_cache.get(1) << endl;
  cout << test_cache.get(2) << endl;
  test_cache.put(3,3);
  test_cache.put(4,4);
  cout << test_cache.get(3) << endl;
  cout << test_cache.get(2) << endl;
  cout << test_cache.get(1) << endl;
  cout << test_cache.get(4) << endl;


  std::cout << "Hello, World!" << std::endl;
  return 0;
}
