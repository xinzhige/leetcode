class TrieNode {
public:
  // Initialize your data structure here.
  TrieNode():is_word(false){ }
  unordered_map<char, TrieNode*> children;
  bool is_word;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode *node = root;
    for (int i = 0; i< word.size(); i++) {
      if (node->children.count(word[i]) == 0){
        node->children[word[i]] = new TrieNode();
      }
      node = node->children[word[i]];
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
    if (key.size() <= 0) {
      return false;
    }
    TrieNode *node = root;
    for (int i = 0; i < key.length(); i++) {
      if (node->children.count(key[i]) == 0) {
        return false;
      }
      node = node->children[key[i]];
    }
    return is_word ? node->is_word : true;
  }
};
