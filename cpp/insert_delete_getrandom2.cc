class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
      index[val].insert(nums.size());
      nums.push_back(val);
      return index[val].size() == 1;
    }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
      if (index[val].empty()) {
        return false;
      }
      int i = *index[val].begin();
      index[val].erase(i);
      if (nums.size() - 1 != i) {
        int t = nums.back();
        nums[i] = t;
        index[t].erase(nums.size() - 1);
        index[t].insert(i);
      }
      nums.pop_back();
      return true;
    }

  /** Get a random element from the collection. */
  int getRandom() {
    return nums[rand() % nums.size()];
  }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> index;
};
