// O(lgn) for peekMax and O(1) for all the other operations
class MaxStack {
public:
  /** initialize your data structure here. */
  MaxStack() {

  }

  void push(int x) {
    nums.insert(nums.begin(), x);
    mymap[x].push_back(nums.begin());
  }

  int pop() {
    int x = *nums.begin();
    mymap[x].pop_back();
    if (mymap[x].empty()) {
      mymap.erase(x);
    }
    nums.pop_front();
    return x;
  }

  int top() {
    return nums.front();
  }

  int peekMax() {
    return mymap.rbegin()->first;
  }

  int popMax() {
    int x = mymap.rbegin()->first;
    // Note here it can not use mymap[x].rbegin() becasue it is the iterator
    // of the iterator not the iterator pointing to the element of nums
    auto it = mymap[x].back();
    mymap[x].pop_back();
    if (mymap[x].empty()) {
      mymap.erase(x);
    }
    nums.erase(it);
    return x;
  }

private:
  map<int, vector<list<int>::iterator>> mymap;
  list<int> nums;
};
