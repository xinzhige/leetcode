class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            if (vowels.find(s[begin]) == string::npos) {
                begin += 1;
            } else if (vowels.find(s[end]) == string::npos) {
                end -= 1;
            } else {
                swap(s[begin], s[end]);
                begin += 1;
                end -= 1;
            }
        }
        return s;
    }
};
