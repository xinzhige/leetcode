class Solution {
public:
  string minWindow(string S, string T) {
    auto s_len = S.size();
    auto t_len = T.size();
    if (s_len < t_len) {
      return "";
    }
    vector<int> appeared(256, 0);
    vector<int> expected(256, 0);
    int min_len = INT_MAX;
    int win_begin = 0;
    int min_begin = 0;
    int count = 0;
    for (int i = 0; i < t_len; ++i) {
      expected[T[i]] += 1;
    }
    for (int win_end = 0; win_end < s_len; ++win_end) {
      if (expected[S[win_end]] > 0) {
        appeared[S[win_end]] += 1;
        if (appeared[S[win_end]] <= expected[S[win_end]]) {
          count += 1;
        }
      }
      if (count == t_len) {
        while (appeared[S[win_begin]] > expected[S[win_begin]] ||
               expected[S[win_begin]] == 0) {
          appeared[S[win_begin]] -= 1;
          win_begin += 1;
        }
        int win_len = win_end - win_begin + 1;
        if (win_len < min_len) {
          min_len = win_len;
          min_begin = win_begin;
        }
      }
    }
    if (min_len == INT_MAX) {
      return "";
    } else {
      return S.substr(min_begin, min_len);
    }
  }
};
