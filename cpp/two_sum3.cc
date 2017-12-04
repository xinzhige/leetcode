class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
                       
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
                                                
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_map<int, bool> mymap; 
        for (int i = 0; i < nums.size(); ++i) {
            int curr = value - nums[i];
            if (mymap.find(nums[i]) == mymap.end()) {
                mymap[curr] = true; 
            } else {
                return true; 
            } 
        } 
        return false;
    }
private:
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
