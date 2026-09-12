/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reverse(ListNode* &preptr,ListNode* &ptr){
        if(ptr == nullptr) return;
        else{
            ListNode* front = ptr -> next;
            ptr -> next = preptr;
            preptr = ptr;
            ptr = front;
            reverse(preptr,ptr);
        }
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* ptr = slow -> next;
        ListNode* preptr = nullptr;
        reverse(preptr,ptr);
        // merge two halfs now
        ListNode* p1 = head;
        ListNode* p2 = preptr;
        while(p2 != nullptr){
            ListNode* t1 = p1 -> next;
            ListNode* t2 = p2 -> next;
            p1 -> next = p2;
            p2 -> next = t1;
            p1 = t1;
            p2 = t2;
        }
        p1 -> next = nullptr;
    }
};
