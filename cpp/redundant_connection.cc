// Use union by rank
class UnionFind {
public:
  UnionFind(int size) {
    for (int i = 0; i < size; ++i) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }
  int find(int i) {
    while (i != parent[i]) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }
  void runUnion(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
      } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
      } else {
        parent[rooty] = rootx;
        rank[rootx] += 1;
      }
    }
  }

private:
  vector<int> parent;
  vector<int> rank;
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(MAX_SIZE);
    for (const auto &e: edges) {
      int x = uf.find(e[0]);
      int y = uf.find(e[1]);
      if (x == y) {
        return e;
      }
      uf.runUnion(x, y);
    }
    return {};
  }
private:
  const int MAX_SIZE= 2000;
};
