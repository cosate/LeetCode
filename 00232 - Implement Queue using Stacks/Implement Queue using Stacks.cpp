class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        int i;
        if(temp.empty())
            return NULL;
        else
        {
            i = temp.top();
            temp.pop();
        }
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
        return i;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        int t;
        if(temp.empty())
            return NULL;
        else
            t = temp.top();
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
        return t;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
    
    stack<int> s;
    stack<int> temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */