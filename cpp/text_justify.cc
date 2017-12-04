class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int L) {
    int words_counts = words.size();
    vector<string> result;
    int curr_length = 0;
    int last_i = 0;
    for (int i = 0; i <= words_counts; ++i) {
      
    }
  }
private:
  void addSpace(string &s, int count) {
    for (int i = 0; i < count; ++i) {
      s.push_back(' ');
    }
  }
};
