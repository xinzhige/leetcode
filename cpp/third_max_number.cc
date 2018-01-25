class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<long> top(3, LONG_MIN);
        for (auto num : nums) {
            if (num <= top[2] || num == top[1] || num == top[0]) {
                continue;
            }
            top[2] = num;
            if (top[1] < top[2]) {
                swap(top[1], top[2]);
            }
            if (top[0] < top[1]) {
                swap(top[0], top[1]);
            }
        }
        return top[2] == LONG_MIN ? top[0] : top[2];
    }
};

/*
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (const int &num : nums) {
            s.insert(num);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
*/
