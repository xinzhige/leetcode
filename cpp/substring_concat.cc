// time: O(n*m), space: O(m)
class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    size_t word_length = L.front().size();
    size_t cat_length = word_length * L.size();
    vector<int> result;
    if (S.size() < cat_length) {
      return result;
    }
    unordered_map<string, int> word_count;
    for (auto const &word : L) {
      ++word_count[word];
    }
    for (auto i = S.begin(); i <= S.end() - cat_length; ++i) {
      unordered_map<string, int> unused(word_count);
      for (auto j = i; j != i + cat_length; j += word_length) {
	auto pos = unused.find(string(j, j + word_length));
	if (pos == unused.end() || pos->second == 0) {
	  break;
	}
	pos->second -= 1;
	if (pos->second == 0) {
	  unused.erase(pos);
	}
      }
      if (unused.size() == 0) {
	result.push_back(i - S.begin());
      }
    }
    return result;
  }
};
