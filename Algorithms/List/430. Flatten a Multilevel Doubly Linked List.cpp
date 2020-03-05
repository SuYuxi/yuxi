/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        std::vector<Node*> stack;
        stack.emplace_back(head);
        Node* node;
        Node* dummy = new Node();
        Node* pre = dummy;
        while(!stack.empty())
        {
            Node* cur = stack.back();
            stack.pop_back();
            pre->next = cur;
            cur->prev = pre;
            
            if(cur->next != nullptr) stack.emplace_back(cur->next);
            if(cur->child != nullptr) 
            {
                stack.emplace_back(cur->child);
                cur->child = nullptr;A
            }
            pre = cur;
        }
        delete dummy;
        head->prev = nullptr;
        return head;
    }
};
