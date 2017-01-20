class Solution {
public:
    string reverseVowels(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            for (; begin < end && !is_vowel(s[begin]); begin++); 
            for (; begin < end && !is_vowel(s[end]); end--); 
            swap(s[begin], s[end]);
	    begin += 1;
            end -= 1;
        }
        return s;
    }
private:
    bool is_vowel(char c) {
        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U') {
            
            return true;
        } else {
            return false; 
        }
    }
};
