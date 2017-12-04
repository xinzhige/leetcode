class LRUCache{
private:
  struct CacheNode{
    int key, val;
    CacheNode(int k, int v):key(k),val(v) {}
  };
  list<CacheNode> cache;
  unordered_map<int, list<CacheNode>::iterator> my_map;
  int cap;
public:
  LRUCache(int capacity):cache(),my_map(),cap(capacity) {
  }
  int get(int key) {
    if (my_map.find(key) == my_map.end()) {
      return -1;
    } else {
      cache.splice(cache.begin(), cache, my_map[key]); // move the current node to the begin
      my_map[key] = cache.begin();
      return my_map[key]->val;
    }
  }
  void set(int key, int value) {
    if(get(key) != -1) {
      my_map[key]->val = value;
    } else {
      cache.push_front(CacheNode(key, value));
      my_map[key] = cache.begin();
      if (cache.size() > cap) {
	my_map.erase(cache.back().key);
	cache.pop_back();
      }
    }
  }
};
