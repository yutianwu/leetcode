class MinStack {
private:
    stack<int> st;
    stack<int> aux;

public:
    void push(int x) {
        st.push(x);
        if (aux.empty()) aux.push(x);
        else {
            if (x <= aux.top())
                aux.push(x);
        }
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (!aux.empty() && aux.top() == top)
            aux.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return aux.top();
    }
};
