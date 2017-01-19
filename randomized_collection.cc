class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = (mymap.find(val) == mymap.end());
        mymap[val].push_back(nums.size());
        nums.push_back(pair<int, int>(val, mymap[val].size() - 1));
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool result = (mymap.find(val) != mymap.end());
        if (result) {
            auto last = nums.back();
            nums[mymap[val].back()] = last;
            nums.pop_back();
            mymap[last.first][last.second] = mymap[val].back();
            mymap[val].pop_back();
            if (mymap[val].empty()) {
                mymap.erase(val);
            }
        }
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> mymap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
