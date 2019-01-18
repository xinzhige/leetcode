// Idea: use a hashmap to memorize if the current character is visited.
// If the tail character is bigger than the current one and its frequency
// is larger than 0, it means there are such tail characters afterwards so
// remove it.
class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> freq;
    unordered_set<char> visited;
    for (const char &ch : s) {
      freq[ch] += 1;
    }
    string result = "0";
    for (const char &ch : s) {
      freq[ch] -= 1;
      if (visited.count(ch) == 0) {
        while (result.back() > ch && freq[result.back()] > 0) {
          visited.erase(result.back());
          result.pop_back();
        }
        visited.insert(ch);
        result += ch;
      }
    }
    return result.substr(1);
  }
};
