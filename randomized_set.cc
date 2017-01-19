class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    
    }
                                
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool has_val = false; 
        if (mymap.find(val) == mymap.end()) {
            has_val = true; 
        } 
        myvec.push_back(val);
        mymap[val] = myvec.size() - 1; 
        return has_val; 
    }
                                                        
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool no_val = false;
        if (mymap.find(val) != mymap.end()) {
            no_val = true; 
        } 
        int index = mymap[val];
        int curr = myvec.back();
        myvec[index] = curr;
        mymap[curr] = index;
        myvec.pop_back();
        return no_val;
    }
                                                                                
    /** Get a random element from the set. */
    int getRandom() {
        int random = rand() % myvec.size();
        return myvec[random];
    }
private:
    unordered_map<int, int> mymap;
    vector<int> myvec;
};
