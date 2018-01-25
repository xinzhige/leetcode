class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result(length + 1, 0);
        for (auto &curr_update : updates) {
            result[curr_update[0]] += curr_update[2];
            result[curr_update[1] + 1] -= curr_update[2];
        }
        for (int i = 1; i < length; ++ i) {
            result[i] += result[i - 1];
        }
        result.pop_back();
        return result;
    }
};
