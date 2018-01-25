class Solution {
public:
    bool detectCapitalUse(string word) {
        int lower = 0;
        int upper = 0;
        for (int letter = 0; letter < word.size(); letter++) {
            if (isupper(word[letter]) && lower > 0) {
                return false;
            } else if (islower(word[letter]) && upper > 1) {
                return false;
            } else if (islower(word[letter])) { 
                lower += 1;
            } else if (isupper(word[letter])) { 
                upper += 1;
            }
        }
        return true; 
    }
};
