class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : averageSize(size), sum (0.0) {
    
    }
    
    double next(int val) {
        sum += val;
        myqueue.emplace(val);
        if (myqueue.size() <= averageSize) {
            return sum / myqueue.size(); 
        } else {
            sum -= myqueue.front();
            myqueue.pop();
            return sum / averageSize;
        } 
    }

private:
    queue<int> myqueue;
    int averageSize;
    double sum;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
