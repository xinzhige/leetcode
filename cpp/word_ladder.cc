// Idea: BFS, use a hashmap to store the level (distance) of the word from
// the beginWord.
class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    set<string> dict;
    for (const auto &word : wordList) {
      dict.insert(word);
    }
    queue<string> q;
    q.push(beginWord);
    map<string, int> wordLevel;
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
              q.push(newWord);
              wordLevel[newWord] = wordLevel[currWord] + 1;
            }
          }
        }
      }
    }
    return 0;
  }
};
