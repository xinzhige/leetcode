class Solution {
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (dict.size() == 0 || start.size() != end.size()) {
      return 0;
    }
    queue<string> word_queue;
    word_queue.push(start);
    dict.erase(start);
    int length = 1;
    while (!word_queue.empty()) {
      int count = word_queue.size();
      for (int i = 0; i < count; ++i) {
	string current = word_queue.front();
	word_queue.pop();
	for (char c = 'a'; c <= 'z'; ++c) {
	  for (int j = 0; j < current.size(); ++j) {
	    if (c == current[j]) {
	      continue;
	    }
	    string tmp = current;
	    tmp.replace(j, 1, 1, c);
	    if (tmp == end) {
	      return length + 1;
	    }
	    if (dict.find(tmp) != dict.end()) {
	      word_queue.push(tmp);
	      dict.erase(tmp);
	    }
	  }
	}
      }
      ++length;
    }
    return 0;
  }
};
