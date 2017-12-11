class LRUCache{
public:
  LRUCache(int capacity) : cache(), mymap(), maxCapacity(capacity) {

  }

  int get(int key) {
    if (mymap.count(key) > 0) {
      cache.splice(cache.begin(), cache, mymap[key]);
      mymap[key] = cache.begin();
      return mymap[key]->value;
    } else {
      return -1;
    }
  }

  void put(int key, int value) {
    if (get(key) != -1) {
      mymap[key]->value = value;
    } else {
      cache.emplace_front(key, value);
      mymap[key] = cache.begin();
      if (cache.size() > maxCapacity) {
        mymap.erase(cache.back().key);
        cache.pop_back();
      }
    }
  }

private:
  struct cacheNode {
    int key;
    int value;
    cacheNode(int k, int v): key(k), value(v) { }
  };
  list<cacheNode> cache;
  unordered_map<int, list<cacheNode>::iterator> mymap;
  int maxCapacity;
};
