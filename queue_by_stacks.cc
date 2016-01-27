class Queue {
public:
  // Push element x to the back of queue.
  void push(int x) {
    stack1.push(x);
  }

  // Removes the element from in front of queue.
  void pop(void) {
    if (!stack2.empty()) {
      stack2.pop();
    } else {
      if (!stack1.empty()) {
        transfer(stack1, stack2);
      } 
      stack2.pop();
    }
  }

  // Get the front element.
  int peek(void) {
    if (!stack2.empty()) {
      return stack2.top();
    } else {
      if (!stack1.empty()) {
        transfer(stack1, stack2);
      }
      return stack2.top();
      }
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return stack1.empty() && stack2.empty();
  }
private:
  stack<int> stack1;
  stack<int> stack2;
  void transfer(stack<int> &s1, stack<int> &s2) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }
};
