class Solution {
public:
  int compress(vector<char>& chars) {
    int result = 0;
    int start = 0;
    for (int i = 0; i < chars.size(); ++i) {
      if (chars[i] != chars[i+1] || i == chars.size() - 1) {
        chars[result] = chars[start];
        result += 1;
        if (i > start) {
          auto str = to_string(i - start + 1);
          for (const auto &c : str) {
            chars[result] = c;
            result += 1;
          }
        }
        start = i + 1;
      }
    }
    return result;
  }
};
