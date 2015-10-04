class Queue {
private:
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> reverse;
        while (!s.empty()) {
            reverse.push(s.top());
            s.pop();
        }
        
        stack<int> tmp;
        tmp.push(x);
        while (!reverse.empty()) {
            tmp.push(reverse.top());
            reverse.pop();
        }
        s = tmp;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!s.empty()) 
            s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};