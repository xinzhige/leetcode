// Recursive
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serializeHelper(root, out);
    return out.str();
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserializeHelper(in);
  }
  void serializeHelper(TreeNode* root, ostringstream& out) {
    if (root == nullptr) {
      out << "# ";
    } else {
      out << root->val << " ";
      serializeHelper(root->left, out);
      serializeHelper(root->right, out);
    }
  }
  TreeNode* deserializeHelper(istringstream& in) {
    string val;
    in >> val;
    if (val == "#") {
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserializeHelper(in);
    root->right = deserializeHelper(in);
    return root;
  }
};


// Iterative
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    queue<TreeNode *> q;
    if (root != nullptr) {
      q.push(root);
    }
    while (!q.empty()) {
      TreeNode *t = q.front();
      q.pop();
      if (t != nullptr) {
        out << t->val << " ";
        q.push(t->left);
        q.push(t->right);
      } else {
        out << "# ";
      }
    }
    return out.str();
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    istringstream in(data);
    queue<TreeNode *> q;
    string val;
    in >> val;
    TreeNode *result = new TreeNode(stoi(val));
    TreeNode *curr = result;
    q.push(curr);
    while (!q.empty()) {
      TreeNode *t = q.front();
      q.pop();
      if (in >> val && val != "#") {
        curr = new TreeNode(stoi(val));
        q.push(curr);
        t->left = curr;
      }
      if (in >> val && val != "#") {
        curr = new TreeNode(stoi(val));
        q.push(curr);
        t->right = curr;
      }
    }
    return result;
  }
};
