/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// DFS, time: O(n), space: O(n)
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
    q.emplace(node);
    while (!q.empty()) {
      auto curr_node = q.front();
      q.pop();
      for (const auto & neighbor : curr_node->neighbors) {
        if (copied.count(neighbor) == 0) {
          auto neighbor_copy = new UndirectedGraphNode(neighbor->label);
          copied[neighbor] = neighbor_copy;
          q.emplace(neighbor);
        }
        copied[curr_node]->neighbors.emplace_back(copied[neighbor]);
      }
    }
    return copied[node];
  }
};
