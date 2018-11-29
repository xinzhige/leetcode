class TrieNode {
public:
  unordered_map<char, TrieNode*> children;
  bool is_word = false;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode *node = root;
    for (const char &c : word) {
      if (node->children.count(c) == 0){
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->is_word = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    return retrieve(word, true);
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    return retrieve(prefix, false);
  }

private:
  TrieNode* root;
  bool retrieve(const string& key, bool is_word) {
    if (key.empty()) {
      return false;
    }
    TrieNode *node = root;
    for (const char &c : key) {
      if (node->children.count(c) == 0) {
        return false;
      }
      node = node->children[c];
    }
    return is_word ? node->is_word : true;
  }
};
