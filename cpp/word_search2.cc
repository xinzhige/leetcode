class Solution {
public:
  struct TrieNode {
    TrieNode(): word(""), child(vector<TrieNode*>(26, nullptr)) {}
    vector<TrieNode*> child;
    string word;
  };

  TrieNode* buildTrie(vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string &w : words) {
      TrieNode* node = root;
      for (const char &c : w) {
        int i = c - 'a';
        if (node->child[i] == nullptr) {
          node->child[i] = new TrieNode();
        }
        node = node->child[i];
      }
      node->word = w;
    }
    return root;
  }

  void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
           vector<string>& result) {
    char c = board[i][j];
    if (c != '#' && node->child[c - 'a'] != nullptr) {
      node = node->child[c - 'a'];
      if (node->word != "") {
        result.push_back(node->word);
        node->word = "";
      }
      board[i][j] = '#';
      for (const auto &dir : dirs) {
        int x = i + dir[0];
        int y = j + dir[1];
        if (x >= 0 && x < m && y >= 0 && y < n) {
          dfs(board, x, y, node, result);
        }
      }
      board[i][j] = c;
    }
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() || board[0].empty()) {
      return {};
    }
    vector<string> result;
    TrieNode* root = buildTrie(words);
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, i, j, root, result);
      }
    }
    return result;
  }
private:
  int m = 0;
  int n = 0;
  vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};
