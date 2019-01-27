/*
// Definition for a Node.
class Node {
public:
int val = NULL;
vector<Node*> children;

Node() {}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/
class Codec {
public:
  string serialize(Node* root) {
    string s("");
    encode(root, s);
    return s;
  }

  void encode(Node* root, string& s){
    if(root != nullptr) {
      s += " " + to_string(root->val) + " " +
        to_string(root->children.size());
      for(auto p:root->children) {
        encode(p, s);
      }
    }
  }

  Node* deserialize(string data) {
    stringstream ss(data);
    return decode(ss);
  }

  Node* decode(stringstream& ss){
    ss.peek();
    if(ss.eof()) {
      return nullptr;
    }
    Node *root = new Node();
    int size;
    ss >> root->val >> size;
    for(int i = 0; i < size; ++i) {
      root->children.push_back(decode(ss));
    }
    return root;
  }
};
