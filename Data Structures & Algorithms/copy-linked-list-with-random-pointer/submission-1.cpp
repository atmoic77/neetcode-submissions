/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*,Node*> map;
        Node* newhead = new Node(head -> val);
        Node* ptr1 = head;
        Node* ptr2 = newhead;
        map[head] = newhead;
        ptr1 = ptr1 -> next;
        while(ptr1 != nullptr){
            Node* newcopy = new Node(ptr1 -> val);
            map[ptr1] = newcopy;
            ptr2 -> next = newcopy;
            ptr2 = ptr2 -> next;
            ptr1 = ptr1 -> next;
        }
        ptr2 -> next = nullptr;
        ptr1 = head;
        ptr2 = newhead;
        while(ptr1 != nullptr){
            ptr2 -> random = map[ptr1 -> random];
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return newhead;
    }
};
