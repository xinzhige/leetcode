// Idea: think of the screen as one dimension and determine how many
// sentences can be filled in.
// Note: 1. construct sentence by adding space between words.
// 2. the last character in each row must be either space to make sure
// a word is not split into two lines or just fit.
class Solution {
public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    string s = "";
    for (auto &word : sentence) {
      s += (word + " ");
    }
    /* start points to the character in s that can be put as the first
       in each row. */
    int start = 0;
    int n = s.size();
    for (int i = 0; i < rows; ++i) {
      start += cols;
      if (s[start % n] == ' ') {
        start += 1;
      } else {
        for (; start > 0 && s[(start - 1) % n] != ' '; --start);
      }
    }
    return start / n;
  }
};
