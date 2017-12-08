// Be careful with the case when vec2d has empty vectors.
class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec2d) {
    for (auto a : vec2d) {
      v.insert(v.end(), a.begin(), a.end());
    }
  }
  int next() {
    int t = i;
    ++i;
    return v[t];
  }
  bool hasNext() {
    return i < v.size();
  }

private:
  vector<int> v;
  int i = 0;
};


// follow-up
class Vector2D {
public:
  Vector2D(vector<vector<int>>& vec2d) {
    x = vec2d.begin();
    end = vec2d.end();
    y = 0;
  }

  int next() {
    int t = y;
    ++y;
    return (*x)[t];
  }

  bool hasNext() {
    while (x != end && y == (*x).size()) {
      ++x;
      y = 0;
    }
    return x != end;
  }

private:
  vector<vector<int>>::iterator x, end;
  int y;
};
