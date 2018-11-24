class MyCircularQueue {
public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : max_size(k) {}

  /** Insert an element into the circular queue. Return true if the operation is successful. */
  bool enQueue(int value) {
    if (container.size() == max_size) {
      return false;
    }
    container.push_back(value);
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is successful. */
  bool deQueue() {
    if (container.empty()) {
      return false;
    }
    container.pop_front();
    return true;
  }

  /** Get the front item from the queue. */
  int Front() {
    if (container.empty()) {
      return -1;
    }
    return container.front();
  }

  /** Get the last item from the queue. */
  int Rear() {
    if (container.empty()) {
      return -1;
    }
    return container.back();
  }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() {
    return container.empty();
  }

  /** Checks whether the circular queue is full or not. */
  bool isFull() {
    return container.size() == max_size;
  }

private:
  list<int> container;
  int max_size;
};
