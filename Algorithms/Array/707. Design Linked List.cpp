class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
		head = nullptr;
		tail = nullptr;
		size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
		if(index >= size || index < 0)
		{
			return -1;
		}
		node *cur = head;
		for(int i = 0; i < index; i += 1)
		{
			cur = cur->next;
		}
		return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
		node *temp= new node(val);
		temp->next = head;
		head = temp;
		if(size == 0) tail = head;
		size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
		node *temp= new node(val);
		if(size == 0)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
		if(index < 0 || index > size) return;
		if(index == 0)
		{
			addAtHead(val);
			return;
		}
		node *pre = head, *cur = head;
		for(int i = 0; i < index; i += 1)
		{
			pre = cur;
			cur = cur->next;
		}
		node *temp = new node(val);
		pre->next = temp;
		temp->next = cur;
		size += 1;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		if(index < 0 || index >= size) return;
		if(index == 0)
		{
			head = head->next;
		}
		else
		{
		node *cur = head;
		for(int i = 0; i < index - 1; i += 1)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		if(index == size - 1) tail = cur;
		}
		size -= 1;
    }

private: 
	struct node {
		node(int _val)
		{
			val = _val;
			next = nullptr;
		}
		int val;
		node *next;
	};
	node *head;
	node *tail;
	int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
