class MinStack {
    std::stack<int> stack;
    std::stack<int> minimum_number;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        if (minimum_number.empty() || val <= minimum_number.top()) minimum_number.push(val);
    }
    
    void pop() {
        if (stack.top() == minimum_number.top()) minimum_number.pop();
        stack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minimum_number.top();
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
