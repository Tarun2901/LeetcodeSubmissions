class MyQueue {
public:
    /** Initialize your data structure here. */
     stack<int> input;
     stack<int> output;
    MyQueue() {
       
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = 0;
        if(output.size()>0)
        {
            ret = output.top();
            output.pop();
            return ret;
        }
        else
        {
        while(input.size()>0)
        {
            int temp = input.top();
            input.pop();
            output.push(temp);
        }
        }
        ret = output.top();
        output.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        int ret = 0;
        if(output.size()>0)
        {
            return output.top();
        }
        else
        {
        while(input.size()>0)
        {
            int temp = input.top();
            input.pop();
            output.push(temp);
            
        }
            ret = output.top();
            return ret;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
       if(input.size() == 0 && output.size() == 0)
       {
           return true;
       }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */