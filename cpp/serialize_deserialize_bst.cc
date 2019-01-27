// DFS
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }

  void serialize(TreeNode* root, ostringstream& out) {
    if (root == nullptr) {
      out << "# ";
    } else {
      out << root->val << " ";
      serialize(root->left, out);
      serialize(root->right, out);
    }
  }

  TreeNode* deserialize(istringstream& in) {
    string val("");
    in >> val;
    if (val == "#") {
      return nullptr;
    }
    TreeNode *root= new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
  }
};


// BFS
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }
    ostringstream out;
    queue<TreeNode *> q;
    q.push(root);
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
    string val("");
    in >> val;
    TreeNode *root = new TreeNode(stoi(val));
    TreeNode *node = root;
    q.push(node);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (in >> val && val != "#") {
        node = new TreeNode(stoi(val));
        q.push(node);
        t->left = node;
      }
      if (in >> val && val != "#") {
        node = new TreeNode(stoi(val));
        q.push(node);
        t->right = node;
      }
    }
    return root;
  }
};
