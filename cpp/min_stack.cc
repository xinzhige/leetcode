// One stack
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_num = INT_MAX;
    }
    
    void push(int x) {
        if(x <= min_num){          
            min_stack.push(min_num);
            min_num = x;
        }
        min_stack.push(x);
    }
    
    void pop() {
        int tmp = min_stack.top();
        min_stack.pop();
        if (tmp == min_num) {
            min_num = min_stack.top();
            min_stack.pop();
        }
    }
    
    int top() {
        return min_stack.top();
    }
    
    int getMin() {
        return min_num;
    }
    
private:
    int min_num;
    stack<int> min_stack;
};


// Two stacks
class MinStack {
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

private:
    stack<int> elements;
    stack<int> minStack;
};
