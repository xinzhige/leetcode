// DFS
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream os;
    serialize(root, os);
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream is(data);
    return deserialize(is);
  }

  void serialize(TreeNode* root, ostringstream& os) {
    if (root == nullptr) {
      os << "# ";
    } else {
      os << root->val << " ";
      serialize(root->left, os);
      serialize(root->right, os);
    }
  }

  TreeNode* deserialize(istringstream& is) {
    string val("");
    is >> val;
    if (val == "#") {
      return nullptr;
    }
    auto node = new TreeNode(stoi(val));
    node->left = deserialize(is);
    node->right = deserialize(is);
    return node;
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
    ostringstream os;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (t != nullptr) {
        os << t->val << " ";
        q.push(t->left);
        q.push(t->right);
      } else {
        os << "# ";
      }
    }
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    istringstream is(data);
    queue<TreeNode *> q;
    string val("");
    is >> val;
    auto node = new TreeNode(stoi(val));
    auto curr = node;
    q.push(curr);
    while (!q.empty()) {
      auto t = q.front();
      q.pop();
      if (!(is >> val)) {
        break;
      }
      if (val != "#") {
        curr = new TreeNode(stoi(val));
        q.push(curr);
        t->left = curr;
      }
      if (!(is >> val)) {
        break;
      }
      if (val != "#") {
        curr = new TreeNode(stoi(val));
        q.push(curr);
        t->right = curr;
      }
    }
    return node;
  }
};
