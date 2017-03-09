class WordDictionary {
public:
    /** Initialize your data structure here. */
    struct TrieNode {
        bool isString = false; 
        unordered_map<char, TrieNode*> children; 
    }; 
    
    WordDictionary() {
        root = new TrieNode();
        root->isString = true;
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        auto* p = root;
        for (const auto& c : word) {
            if (p->children.find(c) == p->children.end()) {
                p->children[c] = new TrieNode(); 
            } 
            p = p->children[c];
        }
        p->isString = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root, 0);
    }
    
    bool search(string word, TrieNode* node, int l) {
        if (word.size() == l) {
            return node->isString; 
        } 
        if (node->children.find(word[l]) != node->children.end()) {
            return search(word, node->children[word[l]], l + 1); 
        } else if (word[l] == '.') {
            for (const auto& curr : node->children) {
                if (search(word, curr.second, l + 1)) { 
                    return true; 
                }
            } 
        } 
        return false;
    }

private:
    TrieNode *root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
