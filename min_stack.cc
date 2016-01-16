class MinStack {
private:
  stack<int> elements;
  stack<int> minStack;
public:
  void push(int x) {
    elements.push(x);
    if (minStack.empty() || x <= minStack.top()) {
      minStack.push(x);
    }
  }

  void pop() {
    if (elements.empty()) {
      return;
    }
    if (element.top() == minStack.top()) {
      minStack.pop();
    }
    element.pop();
  }

  int top() {
    return elements.top();
  }

  int getMin() {
    if (minStack.empty()) {
      return INT_MAX;
    } else {
      return minStack.top();
    }
  }
};
