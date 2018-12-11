class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string, int> wordLevel;
    map<string, bool> dict;
    for (const auto &word : wordList) {
      dict[word] = true;
    }
    queue<string> q;
    q.emplace(beginWord);
    wordLevel[beginWord] = 1;
    while (!q.empty()) {
      string currWord = q.front();
      q.pop();
      for (int i = 0; i < currWord.size(); ++i) {
        string newWord = currWord;
        for (char ch = 'a'; ch < 'z'; ++ch) {
          newWord[i] = ch;
          if (dict.count(newWord) > 0) {
            if (newWord == endWord) {
              return wordLevel[currWord] + 1;
            }
            if (wordLevel.count(newWord) == 0) {
              q.emplace(newWord);
              wordLevel[newWord] = wordLevel[currWord] + 1;
            }
          }
        }
      }
    }
    return 0;
  }
};
