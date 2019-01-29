class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {}

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if (index.count(val) > 0) {
      return false;
    }
    nums.push_back(val);
    index[val] = nums.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if (index.count(val) == 0) {
      return false;
    }
    int last = nums.back();
    nums[index[val]] = last;
    nums.pop_back();
    index[last] = index[val];
    index.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return nums[rand() % nums.size()];
  }
private:
  vector<int> nums;
  unordered_map<int, int> index;
};
