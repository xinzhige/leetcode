class Solution {
public:
  void reverseWords(string &s) {
    string result;
    int j = s.size();
    for (int i = s.size(); i >= 0; i--) {
        if (s[i] == ' ') {
            j = i; 
        } else if (i == 0 || s[i - 1] == ' ') {
            if (!result.empty()) {
                result.append(" "); 
            } 
            result.append(s.substr(i, j - i));
        } 
    }
    s = result;
  }
};
