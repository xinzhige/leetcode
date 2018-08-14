class Solution {
public:
  int maxProduct(vector<string>& words) {
    int result = 0;
    vector<int> mask(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
      for (const auto &c : words[i]) {
        mask[i] |= (1 << (c - 'a'));
      }
      for (int j = 0; j < i; ++j) {
        if ((mask[i] & mask[j]) == 0) {
          int curr = words[i].size() * words[j].size();
          result = (result < curr ? curr : result);
        }
      }
    }
    return result;
  }
};
