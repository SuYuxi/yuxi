#include <limits.h>
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
		if(x <= min) {
			minStack.push(min);
			min = x;
		}
		minStack.push(x);
    }
    
    void pop() {
		if(min == minStack.top()) {
			minStack.pop();
			min = minStack.top();
		}
		minStack.pop();
    }
    
    int top() {
		return minStack.top();
    }
    
    int getMin() {
		return min;
    }
	
private:
	int min = INT_MAX;
	stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
