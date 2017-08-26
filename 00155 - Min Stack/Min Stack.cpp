class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        sta.push(x);
        if(min.empty() || min.top()>=x) min.push(x);
        else min.push(min.top());
    }
    
    void pop() {
        int top = sta.top();
        sta.pop();
        min.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return min.top();
    }
    stack<int> sta;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */