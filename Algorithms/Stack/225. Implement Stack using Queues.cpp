class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
		int len = stack.size();
		stack.emplace(x);
		for(int i = 0; i < len; i++)
		{
			int front = stack.front();
			stack.pop();	
			stack.emplace(front);
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
		int top = stack.front();
		stack.pop();
		return top;
    }
    
    /** Get the top element. */
    int top() {
		return stack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
		return stack.empty();
    }

private:
	std::queue<int> stack;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
