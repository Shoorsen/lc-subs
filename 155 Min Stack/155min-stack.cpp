class MinStack {
public:
    stack<int> items; //0 1 0
    stack<int> st; //0
    MinStack() {}
    
    void push(int val) {
        items.push(val);
        if (st.empty() || st.top() >= val) {
            st.push(val);
        }
    }

    void pop() {
        if (items.top() == st.top()) {
            st.pop();
        }
        items.pop();
    }
    
    int top() {
        return items.top();
    }
    
    int getMin() {
        return st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
