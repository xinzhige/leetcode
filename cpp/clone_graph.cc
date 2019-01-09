// Idea: build a hash-table (old node => new node) and DFS,
// time: O(n), space: O(n)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    if (copied.count(node) == 0) {
      copied[node] = new UndirectedGraphNode(node->label);
      for (const auto &neighbor : node->neighbors) {
        copied[node]->neighbors.push_back(cloneGraph(neighbor));
      }
    }
    return copied[node];
  }

private:
  unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
};

// BFS, time: O(n), space: O(n)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> copied;
    copied[node] = new UndirectedGraphNode(node->label);
    queue<UndirectedGraphNode *> q;
    q.push(node);
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      for (const auto & neighbor : curr->neighbors) {
        if (copied.count(neighbor) == 0) {
          copied[neighbor] = new UndirectedGraphNode(neighbor->label);
          q.push(neighbor);
        }
        copied[curr]->neighbors.push_back(copied[neighbor]);
      }
    }
    return copied[node];
  }
};
