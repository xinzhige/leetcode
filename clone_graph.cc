// DFS, time: O(n), space: O(n)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node == nullptr) {
      return nullptr;
    }
    unordered_map<UndirectedGraphNode *, 
		  UndirectedGraphNode *> copied;
    clone(node, copied);
    return copied[node];
  }
private:
  UndirectedGraphNode* clone(UndirectedGraphNode *node,
				    unordered_map<UndirectedGraphNode *,
				    UndirectedGraphNode *> &copied) {
    if (copied.find(node) != copied.end()) {
      return copied[node];
    }
    UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
    copied[node] = new_node;
    for (auto nbr : node->neighbors) {
      new_node->neighbors.push_back(clone(nbr, copied));
    }
    return new_node;
  }
};

// BFS, time: O(n), space: O(n)
class Solution {
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node == nullptr) {
      return nullptr;
    }
    unordered_map<UndirectedGraphNode *,
		  UndirectedGraphNode *> copied;
    copied[node] = new UndirectedGraphNode(node->label);
    queue<UndirectedGraphNode *> q;
    q.push(node);
    while (!q.empty()) {
      UndirectedGraphNode *curr = q.front();
      q.pop();
      for (auto nbr : curr->neighbors) {
	if (copied.find(nbr) != copied.end()) {
	  copied[curr]->neighbors.push_back(copied[nbr]);
	} else {
	  UndirectedGraphNode *new_node =
	    new UndirectedGraphNode(nbr->label);
	  copied[nbr] = new_node;
	  copied[curr]->neighbors.push_back(new_node);
	  q.push(nbr);
	}
      } 
    }
    return copied[node];
  }
};
