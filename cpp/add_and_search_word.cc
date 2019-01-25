// Trie
class WordDictionary {
public:
  /** Initialize your data structure here. */
  struct TrieNode {
    bool isString;
    unordered_map<char, TrieNode*> children;
  };

  WordDictionary() {
    root = new TrieNode();
    root->isString = true;
  }

  // Adds a word into the data structure.
  void addWord(string word) {
    auto p = root;
    for (const auto& c : word) {
      if (p->children.count(c) == 0) {
        p->children[c] = new TrieNode();
      }
      p = p->children[c];
    }
    p->isString = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return searchWord(word, root, 0);
  }

  bool searchWord(string word, TrieNode* node, int level) {
    if (word.size() == level) {
      return node->isString;
    }
    if (node->children.count(word[level]) > 0) {
      return searchWord(word, node->children[word[level]], level + 1);
    } else if (word[level] == '.') {
      for (const auto& curr : node->children) {
        if (searchWord(word, curr.second, level + 1)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  TrieNode *root;
};
