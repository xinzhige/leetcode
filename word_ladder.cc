class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, int> m;
    unordered_map<string, bool> wordDict;
    for (const auto & w : wordList) {
      wordDict[w] = true;
    }
    queue<string> q;
    m[beginWord] = 1;
    q.push(beginWord);
    while (!q.empty()) {
      string word = q.front(); 
      q.pop();
      for (int i = 0; i < word.size(); ++i) {
	string newWord = word;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
	  newWord[i] = ch;
	  if (wordDict.count(newWord)) {
	    if (newWord == endWord) {
	      return m[word] + 1;
	    }
	    if (m.count(newWord) == 0) {
	      q.emplace(newWord);
	      m[newWord] = m[word] + 1;
	    }
	  }   
	}
      }
    }
    return 0;
  }
};
