class Codec {
public:
    void serializeHelper(TreeNode* root, ostringstream& out) {
      if (root == nullptr) {
        out << "# ";
	return;
      }	   
      out << root->val << " ";
      serializeHelper(root->left, out);
      serializeHelper(root->right, out);
    }
    TreeNode* deserializeHelper(string& in) {
      string val;
      in >> val;
      if (val == "#" || val.empty()) {
        return nullptr;	      
      }
      TreeNode* node = new TreeNode(stoi(val));
      node->left = deserializeHelper(in);
      node->right = desrializeHelper(in);
      return node;
    }
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
};
