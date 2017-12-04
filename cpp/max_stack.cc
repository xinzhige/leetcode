class MaxStack {
public:
  /** initialize your data structure here. */
  MaxStack() {

  }

  void push(int x) {
    add_max(x);
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
      add_max(tmp.top());
      tmp.pop();
    }
    return result;
  }

private:
  void add_max(int x) {
    if (maxstack.empty() || x >= maxstack.top()) {
      maxstack.push(x);
    }
  }
  stack<int> mystack;
  stack<int> maxstack;
};
