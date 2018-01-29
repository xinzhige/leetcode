// O(n) for popMax and O(1) for all the other operations
class MaxStack {
public:
  /** initialize your data structure here. */
  MaxStack() {

  }

  void push(int x) {
    addMax(x);
    mystack.push(x);
  }

  int pop() {
    int curr = mystack.top();
    mystack.pop();
    if (curr == maxstack.top()) {
      maxstack.pop();
    }
    return curr;
  }

  int top() {
    return mystack.top();
  }

  int peekMax() {
    return maxstack.top();
  }

  int popMax() {
    int result = maxstack.top();
    stack<int> tmp;
    while (mystack.top() != maxstack.top()) {
      tmp.push(mystack.top());
      mystack.pop();
    }
    maxstack.pop();
    mystack.pop();
    while (!tmp.empty()) {
      mystack.push(tmp.top());
      // Note it should add the max elements back to the maxstack
      addMax(tmp.top());
      tmp.pop();
    }
    return result;
  }

private:
  void addMax(int x) {
    if (maxstack.empty() || x >= maxstack.top()) {
      maxstack.push(x);
    }
  }
  stack<int> mystack;
  stack<int> maxstack;
};


// O(lgn) for peekMax and O(1) for all the other operations
class MaxStack {
public:
  /** initialize your data structure here. */
  MaxStack() {

  }

  void push(int x) {
    mylist.insert(mylist.begin(), x);
    mymap[x].push_back(mylist.begin());
  }

  int pop() {
    int x = *mylist.begin();
    mymap[x].pop_back();
    if (mymap[x].empty()) {
      mymap.erase(x);
    }
    mylist.pop_front();
    return x;
  }

  int top() {
    return *mylist.begin();
  }

  int peekMax() {
    return mymap.rbegin()->first;
  }

  int popMax() {
    int x = mymap.rbegin()->first;
    // Note here it can not use mymap[x].rbegin() becasue it is the iterator
    // of the iterator not the iterator pointing to the element of mylist
    auto it = mymap[x].back();
    mymap[x].pop_back();
    if (mymap[x].empty()) {
      mymap.erase(x);
    }
    mylist.erase(it);
    return x;
  }

private:
  map<int, vector<list<int>::iterator>> mymap;
  list<int> mylist;
};
