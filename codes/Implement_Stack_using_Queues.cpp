class Stack {
private:
    queue<int> que;
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (que.empty()) return;
        
        queue<int> tmp;
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            if (!que.empty())
                tmp.push(front);
        }
        que = tmp;
    }

    // Get the top element.
    int top() {
        queue<int> tmp;
        while (!que.empty()) {
            int front = que.front();
            que.pop();
            tmp.push(front);
            
            if (que.empty()) {
                que = tmp;
                return front;
            }
        }
        return -1;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};