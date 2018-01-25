class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        char prev = ' ';
        for (const auto &c : s) {
            if (c != ' ' && prev == ' ') {
                count += 1; 
            }
            prev = c;
        }
        return count;
    }
};
