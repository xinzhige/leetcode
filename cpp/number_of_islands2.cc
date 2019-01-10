class UnionFind {
public:
  UnionFind(int N) {
    count = 0;
    for (int i = 0; i < N; ++i) {
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  int findRoot(int i) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }

  void runUnion(int x, int y) {
    int rootx = findRoot(x);
    int rooty = findRoot(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) {
        parent[rooty] = rootx;
      } else if (rank[rootx] < rank[rooty]) {
        parent[rootx] = rooty;
      } else {
        parent[rooty] = rootx;
        rank[rootx] += 1;
      }
      count -= 1;
    }
  }

  int getCount() {
    return count;
  }

  bool isValid(int i) {
    return parent[i] >= 0;
  }

  void setParent(int i) {
    parent[i] = i;
    count += 1;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count;
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> result;
    UnionFind uf (m*n);
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for (const auto& pos : positions) {
      int prev_id = n*pos.first + pos.second;
      uf.setParent(prev_id);
      for (const auto &dir : dirs) {
        int x = pos.first + dir[0];
        int y = pos.second + dir[1];
        int curr_id = x*n + y;
        if (x >= 0 && x < m && y >= 0 && y < n && uf.isValid(curr_id)) {
          uf.runUnion(prev_id, curr_id);
        }
      }
      result.push_back(uf.getCount());
    }
    return result;
  }
};
