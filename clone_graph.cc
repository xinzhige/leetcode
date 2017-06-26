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
    unordered_map<int, UndirectedGraphNode*> mymap;
    return clone(node, mymap);
  }
  UndirectedGraphNode *clone(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode*> &mymap) {
    if (node == nullptr) {
      return node;
    }
    if (mymap.count(node->label)) {
      return mymap[node->label];
    }
    UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
    mymap[node->label] = newNode;
    for (int i = 0; i < node->neighbors.size(); ++i) {
      (newNode->neighbors).emplace_back(clone(node->neighbors[i], mymap));
    }
    return newNode;
  } 
};

// BFS, time: O(n), space: O(n)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    unordered_map<int, UndirectedGraphNode *> copied;
    copied[node->label] = new UndirectedGraphNode(node->label);
    queue<UndirectedGraphNode *> q;
    q.emplace(node);
    while (!q.empty()) {
      UndirectedGraphNode *curr = q.front();
      q.pop();
      for (const auto & nbr : curr->neighbors) {
    	if (copied.find(nbr->label) != copied.end()) {
    	  copied[curr->label]->neighbors.emplace_back(copied[nbr->label]);
    	} else {
    	  UndirectedGraphNode *newNode =
    	    new UndirectedGraphNode(nbr->label);
    	  copied[nbr->label] = newNode;
    	  copied[curr->label]->neighbors.emplace_back(newNode);
    	  q.emplace(nbr);
    	}
      } 
    }
    return copied[node->label];
  }
};
