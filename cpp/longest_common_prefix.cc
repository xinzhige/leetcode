class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        int num_strings = strs.size();
        int len_first_string = strs[0].size();
        for (int j = 0; j < len_first_string; ++j) {
            for (int i = 1; i < num_strings; ++i) {
                if (strs[i][j] != strs[0][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};
