#include <bits/stdc++.h>
using namespace std;

class LRUCache{
public:
  LRUCache(int capacity) {capacity_ = capacity;}
  int get(int key){
    auto it = cache_map.find(key); // it is iteration of map
    if(it == cache_map.end()){ return -1;} // not find
    else{
      cache_list.erase(cache_map[key]);
      cache_list.push_back(it->second);
      cache_map[key] = cache_list.end()-1;
      return cache_map[key]->second;
    }
  }
  void put(int key, int value){
    auto it = cache_map.find(key);
    if(it != cache_map.end()){// key already present
      cache_list.erase(it->second);
    }
    cache_list.push_back(make_pair(key, value));
    cache_map[key] = cache_list.end()-1;
    if(cache_map.size() > capacity_){
      //delete the front pair of the list
      int k = cache_list.begin()->first;//store the key, to update map(delete)
      cache_list.pop_front();
      cache_map.erase(k);//delete cache_map erase(const key);
    }
  }

private:
  int capacity_;
  list<pair<int, int>> cache_list;
  unodered_map<int, list<pair<int, int>> > cache_map;
};