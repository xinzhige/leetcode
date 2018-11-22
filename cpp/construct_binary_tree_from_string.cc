// Recursive
class Solution {
public:
  TreeNode* str2tree(string s) {
    if (s.empty()) {
      return nullptr;
    }
    int i = 0;
    return build(s, i);
  }
  TreeNode* build(string& s, int& i) {
    int start = i;
    if (s[i] == '-') {
      ++i;
    }
    for (; isdigit(s[i]); ++i);
    int num = stoi(s.substr(start, i - start));
    TreeNode* node = new TreeNode(num);
    if (s[i] == '(') {
      ++i;
      node->left = build(s, i);
      ++i;
    }
    if (s[i] == '(') {
      ++i;
      node->right = build(s, i);
      ++i;
    }
    return node;
  }
};


// Iterative
class Solution {
public:
  TreeNode* str2tree(string s) {
    if (s.empty()) {
      return nullptr;
    }
    stack<TreeNode *> st;
    for (int i = 0; i < s.size(); ++i) {
      int j = i;
      if (s[i] == ')') {
        st.pop();
      } else if (isdigit(s[i]) || s[i] == '-') {
        for (; i < s.size() - 1 && isdigit(s[i + 1]); ++i);
        TreeNode *node = new TreeNode(stoi(s.substr(j, i - j + 1)));
        if (!st.empty()) {
          if (st.top()->left == nullptr) {
            st.top()->left = node;
          } else {
            st.top()->right = node;
          }
        }
        st.push(node);
      }
    }
    return st.top();
  }
};
