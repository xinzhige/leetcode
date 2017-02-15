// Brute force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for (auto num : findNums) {
            int i = 0;
            for (; i < nums.size() && nums[i] != num; ++i);
            int j = i + 1;
            for (; j < nums.size() && nums[j] < num; ++j);
            if (j == nums.size()) {
                result.emplace_back(-1); 
            } else {
                result.emplace_back(nums[j]); 
            }
        }
        return result;
    }
};


// Use stack and unordered_map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        stack<int> mystack;
        unordered_map<int, int> mymap;
        for (auto num : nums) {
            while (!mystack.empty() && mystack.top() < num) {
                mymap[mystack.top()] = num;
                mystack.pop();
            } 
            mystack.emplace(num);
        }
        for (auto elem : findNums) {
            int tmp = (mymap.find(elem) == mymap.end()) ? -1 : mymap[elem]; 
            result.emplace_back(tmp);
        }
        return result;
    }
};
