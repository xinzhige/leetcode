class Solution {
public:
  string minWindow(string S, string T) {
    auto s_len = S.size();
    auto t_len = T.size();
    if (s_len < t_len) {
      return "";
    }
    const int ASCII_MAX = 256;
    vector<int> appeared(ASCII_MAX, 0);
    vector<int> expected(ASCII_MAX, 0);
    int min_width = INT_MAX;
    int win_begin = 0;
    int min_begin = 0;
    int count = 0;
    for (int i = 0; i < t_len; ++i) {
      ++expected[T[i]];
    }
    for (int win_end = 0; win_end < s_len; ++win_end) {
      if (expected[S[win_end]] > 0) {
        ++appeared[S[win_end]];
        if (appeared[S[win_end]] <= expected[S[win_end]]) {
          ++count;
        }
      }
      if (count == t_len) {
        while (appeared[S[win_begin]] > expected[S[win_begin]] ||
               expected[S[win_begin]] == 0) {
          --appeared[S[win_begin]];
          ++win_begin;
        }
        int window_length = win_end - win_begin + 1;
        if (min_width > window_length) {
          min_width = window_length;
          min_begin = win_begin;
        }
      }
    }
    if (min_width == INT_MAX) {
      return "";
    } else {
      return S.substr(min_begin, min_width);
    }
  }
};
