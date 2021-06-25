class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> input;
    queue<int> output;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        //Push the element in the other queue
        output.push(x);
        //Remove and push all elements from input to output
        while(input.size()>0)
        {
            int t = input.front();
            input.pop();
            output.push(t);
        }
        //Swap input and output
        queue<int> temp = input;
        input = output;
        output = temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = input.front();
        input.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return input.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(input.size()>0)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */