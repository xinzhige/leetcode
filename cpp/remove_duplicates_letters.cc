// Idea: use a hashmap to memorize if the current character is visited.
// If the tail character is bigger than the current one and its frequency
// is larger than 0, it means there are such tail characters afterwards so
// remove it.
class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> freq;
    unordered_map<char, bool> visited;
    for (const char &ch : s) {
      freq[ch] += 1;
    }
    string result = "0";
    for (const char &ch : s) {
      freq[ch] -= 1;
      if (!visited[ch]) {
        while (result.back() > ch && freq[result.back()] > 0) {
          visited[result.back()] = false;
          result.pop_back();
        }
        result += ch;
        visited[ch] = true;
      }
    }
    return result.substr(1);
  }
};
