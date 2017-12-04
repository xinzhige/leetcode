class Solution {
public:
    void removeSpace(string &s){  
        for (int i = 0; i < s.length(); ++i) {  
            while (s[i] == ' ' && 
                   (i == s.length() - 1 || i == 0 || s[i + 1] == ' ')) { 
                s.erase(i, 1);  
            }  
        }  
    }  
    void reverseWords(string &s) {  
        removeSpace(s);
        reverse(s.begin(), s.end()); 
        for (int i = 0, j = 0; j <= s.length(); ++j) {
            if (j == s.length() || s[j] == ' ') {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
    }  
};
