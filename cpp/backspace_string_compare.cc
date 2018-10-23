class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int i = S.size() - 1;
    int j = T.size() - 1;
    while (true) {
      for (int back = 0; i >= 0 && (back > 0 || S[i] == '#'); --i) {
        back += (S[i] == '#' ? 1 : -1);
      }
      for (int back = 0; j >= 0 && (back > 0 || T[j] == '#'); --j) {
        back += (T[j] == '#' ? 1 : -1);
      }
      if (i >= 0 && j >= 0 && S[i] == T[j]) {
        --i;
        --j;
      } else {
        break;
      }
    }
    return i == -1 && j == -1;
  }
};
