class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int digit = 0;
        for (const auto &c : abbr) {
            if (isdigit(c)) {
                if (c == '0' && digit == 0) {
                    return false; 
                }
                digit = 10 * digit + c - '0';
            } else {
                if (digit > 0) {
                    i += digit;
                    digit = 0;
                }
                if (i >= word.size() || word[i] != c) {
                    return false; 
                }
                i += 1; 
            }
        }
        if (digit > 0) {
            i += digit; 
        }
        if (i == word.size()) {
            return true; 
        } else {
            return false; 
        }
    }
};
