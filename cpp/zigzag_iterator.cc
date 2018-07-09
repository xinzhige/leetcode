class ZigzagIterator {
public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    ind = 0;
    head[0] = v1.begin();
    head[1] = v2.begin();
    tail[0] = v1.end();
    tail[1] = v2.end();
  }

  int next() {
    int next;
    if (head[0] == tail[0]) {
      next = *head[1];
      head[1] += 1;
    } else if (head[1] == tail[1]) {
      next = *head[0];
      head[0] += 1;
    } else {
      next = *head[ind];
      head[ind] += 1;
      ind = 1 - ind;
    }
    return next;
  }

  bool hasNext() {
    return head[0] != tail[0] || head[1] != tail[1];
  }
private:
  int ind;
  vector<int>::iterator head[2];
  vector<int>::iterator tail[2];
};


// K vectors
class ZigzagIterator {
public:
  ZigzagIterator(vector<vector<int>>& v) {
    for (const auto & i : v) {
      if (i.size() > 0) {
        myq.emplace(i.begin(), i.end());
      }
    }
  }

  int next() {
    auto it1 = myq.front().first();
    auto it2 = myq.front().second;
    myq.pop();
    if (it1 + 1 != it2) {
      myq.emplace(it1 + 1, it2);
    }
    return *it1;
  }

  bool hasNext() {
    return !myq.empty();
  }
private:
  queue<pair<vector<int>::iterator, vector<int>::iterator>> myq;
};

