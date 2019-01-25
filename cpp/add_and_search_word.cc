// Trie
class WordDictionary {
public:
  /** Initialize your data structure here. */
  struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
  };

  WordDictionary() {
    root = new TrieNode();
    root->isWord = true;
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
    p->isWord = true;
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return searchWord(word, root, 0);
  }

  bool searchWord(string &word, TrieNode* root, int level) {
    if (word.size() == level) {
      return root->isWord;
    }
    if (root->children.count(word[level]) > 0) {
      return searchWord(word, root->children[word[level]], level + 1);
    } else if (word[level] == '.') {
      for (const auto& node: root->children) {
        if (searchWord(word, node.second, level + 1)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  TrieNode *root;
};
