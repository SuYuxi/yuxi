class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		while(!s1.empty())
		{
			s2.emplace(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			s1.emplace(s2.top());
			s2.pop();
		}
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int front = s1.top();
		s1.pop();
		return front;
    }
    
    /** Get the front element. */
    int peek() {
		return s1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return s1.empty();
    }

private:
	std::stack<int> s1, s2;
};

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
		s1.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.emplace(s1.top());
				s1.pop();
			}
		}
		int front = s2.top();
		s2.pop();
		return front;
    }
    
    /** Get the front element. */
    int peek() {
		if(s2.empty())
		{
			while(!s1.empty())
			{
				s2.emplace(s1.top());
				s1.pop();
			}
		}
		return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
		return s1.empty() && s2.empty();
    }

private:
	std::stack<int> s1, s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
