class Solution {
public:
  string minWindow(string S, string T) {
    size_t S_length = S.size();
    size_t T_length = T.size();
    if (S_length == 0 || S_length < T_length) {
      return "";
    }
    const int ASCII_MAX = 256;
    vector<size_t> appeared_count(ASCII_MAX, 0);
    vector<size_t> expected_count(ASCII_MAX, 0);
    int min_width = INT_MAX;
    int window_begin = 0;
    int min_begin = 0;
    int appeared = 0;
    for (size_t i = 0; i < T_length; ++i) {
      ++expected_count[T[i]];
    }
    for (size_t window_end = 0; window_end < S_length; ++window_end) {
      if (expected_count[S[window_end]] > 0) {
	++appeared_count[S[window_end]];
	if (appeared_count[S[window_end]] <= expected_count[S[window_end]]) {
	  ++appeared;
	}
      }
      if (appeared == T_length) {
	while (appeared_count[S[window_begin]] > expected_count[S[window_begin]] || 
	       expected_count[S[window_begin]] == 0) {
	  --appeared_count[S[window_begin]];
	  ++window_begin;
	}
	int window_length = window_end - window_begin + 1;
	if (min_width > window_length) {
	  min_width = window_length;
	  min_begin = window_begin;
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
