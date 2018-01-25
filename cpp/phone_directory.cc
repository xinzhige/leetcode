class PhoneDirectory {
public:
    /** Initialize your data structure here
            @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) :
        curr(0), numbers(maxNumbers), used(maxNumbers) {  // Time: O(n), Space: O(n)
        iota(numbers.begin(), numbers.end(), 0);
    }
                                                                
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {  // Time: O(1), Space: O(1)
        if (curr == numbers.size()) {
            return -1;
        }
        const auto number = numbers[curr];
        curr++;
        used[number] = true;
        return number;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {  // Time: O(1), Space: O(1)
        if (number < 0 || number >= numbers.size()) {
            return false;
        }
        return !used[number];
    }

    /** Recycle or release a number. */
    void release(int number) {  // Time: O(1), Space: O(1)
        if (number < 0 || number >= numbers.size() || !used[number]) {
            return;
        }
        used[number] = false;
        curr--;
        numbers[curr] = number;
    }

private:
    int curr;
    vector<int> numbers;
    vector<bool> used;
};
/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
